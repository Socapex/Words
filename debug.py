import wx
import wx.stc as stc

class MyOutput1(stc.StyledTextCtrl):
    def __init__(self, parent, pos, size ):
        super( MyOutput1, self ).__init__( parent, pos=pos, size=size, style=wx.TE_MULTILINE )

        self.StyleSetSpec( stc.STC_STYLE_DEFAULT, "size:10,face:DejaVu Sans Mono,fore:#EEEEEE,back:#181818" );
        self.StyleClearAll();
        self.SetLexer( stc.STC_LEX_PYTHON );

        self.SetMarginType(0, wx.stc.STC_MARGIN_NUMBER)
        self.SetMarginWidth(0, 25)
        self.StyleSetSpec( wx.stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New")
        f = "size:10,face:DejaVu Sans Mono"
        #self.SetKeyWords(0, "CAnalysis CDebug CMain CGenerateSentence CInputEnglish COption CWord");
        #self.SetKeyWords(1, "PROGRAM START END EXIT");
        
        self.StyleSetSpec( stc.STC_P_WORD2, "fore:#FF0000" );
        self.StyleSetSpec( stc.STC_P_COMMENTLINE, "fore:#444444" );
        self.StyleSetSpec( stc.STC_P_DEFAULT, "size:10,face:Courier New,back:#181818" );
        self.StyleSetSpec( stc.STC_P_COMMENTBLOCK, "fore:#FAB000,bold");
        self.StyleSetSpec( stc.STC_P_NUMBER, "fore:#B479FF" + f  );
        self.StyleSetSpec( stc.STC_P_STRING, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_CHARACTER, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_WORD, "fore:#00DEE8" + f ); #Keywords
        self.StyleSetSpec( stc.STC_P_TRIPLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_TRIPLEDOUBLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_CLASSNAME, "fore:#1F8BF4,bold" );
        self.StyleSetSpec( stc.STC_P_DEFNAME, "fore:#66E712,bold"  );
        self.StyleSetSpec( stc.STC_P_OPERATOR, "fore:#AAAAAA,bold" + f  );
        # Tab width.
        self.SetIndent( 4 );
        self.SetTabIndents( True );
        self.SetIndentationGuides( True );
        
        ## Line Number.
        self.SetMarginType( 0, stc.STC_MARGIN_NUMBER );
        self.SetMarginMask( 1, 0 );
        self.SetMarginWidth( 0, 30 );
        self.StyleSetSpec( stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New,fore:#888888,back:#181818" );
        
        with open( "C:/Words/Project1/Debug/D_OUT1.txt", 'rb' ) as f:
            content = f.read();

        self.SetText(content);
        self.SetReadOnly(True);

class MyOutput2(stc.StyledTextCtrl):
    def __init__(self, parent, pos, size ):
        super( MyOutput2, self ).__init__( parent, pos=pos, size=size, style=wx.TE_MULTILINE )

        self.StyleSetSpec( stc.STC_STYLE_DEFAULT, "size:10,face:DejaVu Sans Mono,fore:#EEEEEE,back:#181818" );
        self.StyleClearAll();
        self.SetLexer( stc.STC_LEX_PYTHON );

        self.SetMarginType(0, wx.stc.STC_MARGIN_NUMBER)
        self.SetMarginWidth(0, 25)
        self.StyleSetSpec( wx.stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New")
        f = "size:10,face:DejaVu Sans Mono"
        #self.SetKeyWords(0, "CAnalysis CDebug CMain CGenerateSentence CInputEnglish COption CWord");
        #self.SetKeyWords(1, "PROGRAM START END EXIT");
        
        self.StyleSetSpec( stc.STC_P_WORD2, "fore:#FF0000" );
        self.StyleSetSpec( stc.STC_P_COMMENTLINE, "fore:#444444" );
        self.StyleSetSpec( stc.STC_P_DEFAULT, "size:10,face:Courier New,back:#181818" );
        self.StyleSetSpec( stc.STC_P_COMMENTBLOCK, "fore:#FAB000,bold");
        self.StyleSetSpec( stc.STC_P_NUMBER, "fore:#B479FF" + f  );
        self.StyleSetSpec( stc.STC_P_STRING, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_CHARACTER, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_WORD, "fore:#00DEE8" + f ); #Keywords
        self.StyleSetSpec( stc.STC_P_TRIPLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_TRIPLEDOUBLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_CLASSNAME, "fore:#1F8BF4,bold" );
        self.StyleSetSpec( stc.STC_P_DEFNAME, "fore:#66E712,bold"  );
        self.StyleSetSpec( stc.STC_P_OPERATOR, "fore:#AAAAAA,bold" + f  );
        # Tab width.
        self.SetIndent( 4 );
        self.SetTabIndents( True );
        self.SetIndentationGuides( True );
        
        ## Line Number.
        self.SetMarginType( 0, stc.STC_MARGIN_NUMBER );
        self.SetMarginMask( 1, 0 );
        self.SetMarginWidth( 0, 30 );
        self.StyleSetSpec( stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New,fore:#888888,back:#181818" );
        
        with open( "C:/Words/Project1/Debug/D_OUT2.txt", 'rb' ) as f:
            content = f.read();

        self.SetText(content);
        self.SetReadOnly(True);

class MyWindow(stc.StyledTextCtrl):
    def __init__(self, parent, pos, size ):
        super( MyWindow, self ).__init__( parent, pos=pos, size=size, style=wx.TE_MULTILINE )

        self.StyleSetSpec( stc.STC_STYLE_DEFAULT, "size:10,face:DejaVu Sans Mono,fore:#EEEEEE,back:#181818" );
        self.StyleClearAll();
        self.SetLexer( stc.STC_LEX_PYTHON );

        ##self.SetMarginType(0, wx.stc.STC_MARGIN_NUMBER)
        ##self.SetMarginWidth(0, 25)
        ##self.StyleSetSpec( wx.stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New,fore:#FF0000")

        f = "size:10,face:DejaVu Sans Mono"
        self.SetKeyWords(0, "CAnalysis CDebug CMain CGenerateSentence CInputEnglish COption CWord");
        self.SetKeyWords(1, "PROGRAM START END EXIT");
        
        self.StyleSetSpec( stc.STC_P_WORD2, "fore:#FF0000" );
        self.StyleSetSpec( stc.STC_P_COMMENTLINE, "fore:#444444" );
        self.StyleSetSpec( stc.STC_P_DEFAULT, "size:10,face:Courier New,back:#181818" );
        self.StyleSetSpec( stc.STC_P_COMMENTBLOCK, "fore:#FAB000,bold");
        self.StyleSetSpec( stc.STC_P_NUMBER, "fore:#B479FF" + f  );
        self.StyleSetSpec( stc.STC_P_STRING, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_CHARACTER, "fore:#E7DC63" + f  );
        self.StyleSetSpec( stc.STC_P_WORD, "fore:#00DEE8" + f ); #Keywords
        self.StyleSetSpec( stc.STC_P_TRIPLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_TRIPLEDOUBLE, "fore:#319D5A,bold" + f  );
        self.StyleSetSpec( stc.STC_P_CLASSNAME, "fore:#1F8BF4,bold" );
        self.StyleSetSpec( stc.STC_P_DEFNAME, "fore:#66E712,bold"  );
        self.StyleSetSpec( stc.STC_P_OPERATOR, "fore:#AAAAAA,bold" + f  );
        # Tab width.
        self.SetIndent( 4 );
        self.SetTabIndents( True );
        self.SetIndentationGuides( True );
        
        ## Line Number.
        self.SetMarginType( 0, stc.STC_MARGIN_NUMBER );
        self.SetMarginMask( 1, 0 );
        self.SetMarginWidth( 0, 30 );
        self.StyleSetSpec( stc.STC_STYLE_LINENUMBER, "size:8,face:Courier New,fore:#888888,back:#181818" );
        
        with open( "C:/Words/Project1/Debug/D_FLOW.txt", 'rb' ) as f:
            content = f.read();

        self.SetText(content);
        self.SetReadOnly(True);

class MyApp(wx.Frame):
    def __init__(self, parent ):
        super( MyApp, self ).__init__( parent=None,  title="Words", size=(500, 500))

        toolbar = self.CreateToolBar()
        self.b1 = wx.Button( toolbar, -1, "Flow", wx.DefaultPosition, wx.DefaultSize )
        self.b2 = wx.Button( toolbar, -1, "Out1", wx.DefaultPosition, wx.DefaultSize )
        self.b3 = wx.Button( toolbar, -1, "Out2", wx.DefaultPosition, wx.DefaultSize )
        tool1 = toolbar.AddControl( self.b1 );
        tool2 = toolbar.AddControl( self.b2 );
        tool3 = toolbar.AddControl( self.b3 );

        toolbar.Realize()

        self.Bind(wx.EVT_BUTTON, self.OnFlow, self.b1)
        self.Bind(wx.EVT_BUTTON, self.OnOut1, self.b2)
        self.Bind(wx.EVT_BUTTON, self.OnOut2, self.b3)

        self.flow = MyWindow(self, wx.Point(0, 0), wx.Size(500, 500));
        self.out1 = MyOutput1(self, wx.Point(0, 0), wx.Size(500, 500));
        self.out2 = MyOutput2(self, wx.Point(0, 0), wx.Size(500, 500));

        self.flow.Show();
        self.out1.Hide();
        self.out2.Hide();

    def OnFlow(self, e):
        self.flow.Show();
        self.out1.Hide();
        self.out2.Hide();

    def OnOut1(self, e):
        self.flow.Hide();
        self.out1.Show();
        self.out2.Hide();

    def OnOut2(self, e):
        self.flow.Hide();
        self.out1.Hide();
        self.out2.Show();        
        
def main():
    app = wx.App()
    frame = MyApp(0);
    frame.Show();
    app.MainLoop()


if __name__ == '__main__':
    main()
