	push {lr}
	adds r1, r0, #0
	ldr r0, _080477F4 @ =0x030000C4
	ldr r2, [r0]
	cmp r2, #0
	bne _080477F8
	movs r0, #0
	b _0804784C
	.align 2, 0
_080477F4: .4byte 0x030000C4
_080477F8:
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _08047824
	ldr r0, _0804781C @ =TextBox_StateType
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r2, r3
	str r0, [r1]
	ldr r0, _08047820 @ =0x00000183
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	b _08047838
	.align 2, 0
_0804781C: .4byte TextBox_StateType
_08047820: .4byte 0x00000183
_08047824:
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	str r0, [r1]
	ldr r1, _08047850 @ =TextBox_StateRenderAll
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
_08047838:
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	subs r1, #0xf
	movs r0, #0xff
	strb r0, [r1, #0x15]
	adds r0, r2, #0
	bl TextBox_RefreshFace
_0804784C:
	pop {r1}
	bx r1
	.align 2, 0
_08047850: .4byte TextBox_StateRenderAll
