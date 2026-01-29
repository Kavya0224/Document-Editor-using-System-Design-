#include <bits/stdc++.h>
using namespace std;
class DocumentEditor
{
private:
    vector<string> elements;
    string renderedDocument;

public:
    void addtext(string text)
    {
        elements.push_back(text);
    }
    void addImage(string imagePath)
    {
        elements.push_back(imagePath);
    }
    string render()
    {
        if (renderedDocument.empty())
        {
        }
        string result;
        for (auto ele : elements)
        {
            if (ele.size() > 4 && (ele.substr(ele.size() - 4) == ".jpg" || ele.substr(ele.size() - 4) == ".png"))
            {
                result += "{Image:" + ele + '}' + '\n';
            }
            else
            {
                result += ele + '\n';
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }
    void saveToFile()
{
    ofstream file("document.txt");
    if (file.is_open())
    {
        file << render();
        file.close();
        cout << "Document Saved" << endl;
    }
    else
    {
        cout << "Error:Unable to open file" << endl;
    }
}

};
int main()
{
    DocumentEditor editor;
    editor.addtext("Hello World");
    editor.addImage("picture.jpg");

    cout << editor.render() << endl;
    editor.saveToFile();

    return 0;
}