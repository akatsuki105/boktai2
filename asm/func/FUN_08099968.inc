	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _080999F4 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _080999F8 @ =0x00004018
	adds r0, r4, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl weapon_080993e4
	adds r0, r4, #0
	movs r1, #5
	movs r2, #7
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _080999FC @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08099A00 @ =0x0000264C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08099A08
	ldr r1, _08099A04 @ =0x00002644
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #0
	b _08099A16
	.align 2, 0
_080999F4: .4byte 0x00004014
_080999F8: .4byte 0x00004018
_080999FC: .4byte 0x00000F56
_08099A00: .4byte 0x0000264C
_08099A04: .4byte 0x00002644
_08099A08:
	cmp r0, #5
	bne _08099A24
	ldr r2, _08099A20 @ =0x00002644
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #3
_08099A16:
	movs r3, #1
	bl MainSprite_SetPose
	b _08099A34
	.align 2, 0
_08099A20: .4byte 0x00002644
_08099A24:
	ldr r1, _08099AB4 @ =0x00002644
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
_08099A34:
	adds r0, r4, #0
	bl FUN_08098edc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080995b0
	adds r0, r4, #0
	bl FUN_08098bdc
	adds r0, r4, #0
	bl FUN_08098d98
	adds r0, r4, #0
	bl FUN_080996e0
	adds r0, r4, #0
	bl FUN_08099650
	movs r1, #0x10
	rsbs r1, r1, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808c61c
	movs r5, #1
	rsbs r5, r5, #0
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0808c658
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099AC8
	ldr r0, _08099AB8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099ABC @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08099AC0 @ =0x00004003
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityCC28_ShowLineInstant
	ldr r1, _08099AC4 @ =FUN_08098f7c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _08099B12
	.align 2, 0
_08099AB4: .4byte 0x00002644
_08099AB8: .4byte 0x0000144C
_08099ABC: .4byte 0x000020AC
_08099AC0: .4byte 0x00004003
_08099AC4: .4byte FUN_08098f7c
_08099AC8:
	ldr r0, _08099B24 @ =0x0000282C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl EntityCC28_DrawHP
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl EntityCC28_DrawEne
	ldr r1, _08099B28 @ =0x00004002
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x14
	ldr r2, _08099B2C @ =0x00004003
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl EntityCC28_ShowLineInstant
	ldr r1, _08099B30 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
_08099B12:
	ldr r0, _08099B34 @ =0x03003E78
	ldr r1, _08099B38 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099B24: .4byte 0x0000282C
_08099B28: .4byte 0x00004002
_08099B2C: .4byte 0x00004003
_08099B30: .4byte FUN_08099008
_08099B34: .4byte 0x03003E78
_08099B38: .4byte 0xFFFFFDFF
