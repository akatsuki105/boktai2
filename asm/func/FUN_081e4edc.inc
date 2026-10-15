	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r7, #0
	bl FUN_081e2960
	adds r0, r7, #0
	bl FUN_081e3dec
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r2, _081E4F18 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4F1C
	movs r0, #1
	b _081E4F1E
	.align 2, 0
_081E4F18: .4byte 0x00001610
_081E4F1C:
	movs r0, #0
_081E4F1E:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E4F26
	b _081E511C
_081E4F26:
	ldr r0, _081E50CC @ =FUN_081e7414
	movs r1, #4
	str r0, [r7, #0x18]
	ldr r2, _081E50D0 @ =0x00001614
	adds r0, r7, r2
	movs r2, #0
	mov sl, r2
	movs r2, #1
	strb r2, [r0]
	ldr r2, _081E50D4 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	bl TextPanel_Hide
	ldr r1, _081E50D8 @ =0x00001604
	adds r4, r7, r1
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r0, [r5]
	ldr r1, _081E50DC @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r4, _081E50E0 @ =0x030046A0
	ldr r2, [r4]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl Video_SetBGLayer
	mov r2, sl
	str r2, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r0, #0x81
	lsls r0, r0, #4
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	ldr r1, _081E50E4 @ =0x00001619
	adds r0, r7, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #2
	adds r0, r7, r1
	movs r2, #0x11
	mov sb, r2
	mov r1, sb
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E50E8 @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E50EC @ =0x000014CC
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r2, _081E50F0 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E50F4 @ =0x00000E28
	adds r0, r7, r1
	movs r1, #0x24
	bl ClearMemory
	ldr r2, _081E50F8 @ =0x00000E04
	adds r0, r7, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r2, sl
	str r2, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	str r2, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	ldr r0, [r5]
	ldr r1, _081E50FC @ =0x000015F0
	adds r4, r7, r1
	ldr r1, [r4]
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
	adds r0, r7, #0
	bl FUN_081e3680
	ldr r2, _081E5100 @ =0x000015E2
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	ldr r1, _081E5104 @ =0x0000161A
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r1, #0x12
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081E5108 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	bl FUN_08049f5c
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E5110 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E5114 @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E5118 @ =0x0000860E
	b _081E5242
	.align 2, 0
_081E50CC: .4byte FUN_081e7414
_081E50D0: .4byte 0x00001614
_081E50D4: .4byte 0x00001616
_081E50D8: .4byte 0x00001604
_081E50DC: .4byte 0x00000BB8
_081E50E0: .4byte 0x030046A0
_081E50E4: .4byte 0x00001619
_081E50E8: .4byte 0x000014B4
_081E50EC: .4byte 0x000014CC
_081E50F0: .4byte 0x000014CE
_081E50F4: .4byte 0x00000E28
_081E50F8: .4byte 0x00000E04
_081E50FC: .4byte 0x000015F0
_081E5100: .4byte 0x000015E2
_081E5104: .4byte 0x0000161A
_081E5108: .4byte 0x00001590
_081E510C: .4byte 0x00001610
_081E5110: .4byte 0x00001617
_081E5114: .4byte 0x00001514
_081E5118: .4byte 0x0000860E
_081E511C:
	ldr r0, _081E5254 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r7, #0x18]
	ldr r0, _081E5258 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E525C @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r2, _081E5260 @ =0x00001610
	adds r1, r7, r2
	movs r4, #2
	rsbs r4, r4, #0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E5264 @ =0x00001604
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #3
	bl Video_SetBGLayer
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _081E5268 @ =0x00001619
	adds r0, r7, r1
	strb r6, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E526C @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _081E5270 @ =0x000014CC
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _081E5274 @ =0x000014CE
	adds r1, r7, r0
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E5278 @ =0x0000161A
	adds r5, r7, r1
	strb r2, [r5]
	ldr r2, _081E527C @ =0x00001608
	adds r4, r7, r2
	ldr r0, [r4]
	subs r2, #0x78
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	bl TextPanel_Start
	adds r0, r7, #0
	bl FUN_081e4544
	ldrb r1, [r5]
	ldr r2, _081E5280 @ =0x00001617
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _081E5284 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	mov r2, r8
	ldr r0, [r2]
	ldr r2, _081E5288 @ =0x000015F0
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0
	bl TextPanel_SetMessage
	mov r2, r8
	ldr r0, [r2]
	bl TextPanel_Start
	ldr r0, _081E5260 @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E528C @ =0x0001010E
_081E5242:
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5254: .4byte FUN_081e6f28
_081E5258: .4byte 0x00001614
_081E525C: .4byte 0x00001616
_081E5260: .4byte 0x00001610
_081E5264: .4byte 0x00001604
_081E5268: .4byte 0x00001619
_081E526C: .4byte 0x000014B4
_081E5270: .4byte 0x000014CC
_081E5274: .4byte 0x000014CE
_081E5278: .4byte 0x0000161A
_081E527C: .4byte 0x00001608
_081E5280: .4byte 0x00001617
_081E5284: .4byte 0x030046A0
_081E5288: .4byte 0x000015F0
_081E528C: .4byte 0x0001010E
