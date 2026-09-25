	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	adds r0, #0x24
	ldrb r5, [r0]
	cmp r5, #0
	beq _0820DBBA
	cmp r5, #1
	bne _0820DBB8
	b _0820DEF4
_0820DBB8:
	b _0820E06E
_0820DBBA:
	ldr r0, [r7, #0x74]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820DC98 @ =0x00000494
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r3, _0820DC9C @ =0x000004F4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0820DCA0 @ =0x00000554
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d21c
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	str r0, [sp, #0x14]
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov sb, r0
	movs r1, #0
	mov r8, r1
	str r4, [sp, #0x34]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sl, r3
	ldr r0, _0820DCA4 @ =0x00000854
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0820DCA8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x28]
	adds r2, r7, #0
	adds r2, #0x4c
	str r2, [sp, #0x3c]
	ldr r3, _0820DCAC @ =0x00000D94
	adds r3, r7, r3
	str r3, [sp, #0x30]
	ldr r0, _0820DCB0 @ =0x00000E54
	adds r0, r7, r0
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0x26
	str r1, [sp, #0x38]
	ldr r2, _0820DCB4 @ =0x00000D8C
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	ldr r3, _0820DCB8 @ =0x00000E4C
	adds r3, r7, r3
	str r3, [sp, #0x20]
	cmp r5, sb
	bge _0820DCD8
	adds r6, r7, #0
	adds r6, #0x28
	movs r4, #5
_0820DC64:
	ldr r0, [r6]
	ldr r2, _0820DCBC @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r6]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	adds r2, r4, #0
	movs r3, #0x14
	bl TextPanel_SetRect
	ldr r5, [sp, #0x14]
	add r5, r8
	adds r0, r5, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820DCC0
	ldr r0, [r6]
	adds r1, r5, #0
	bl TextPanel_SetMessage
	b _0820DCC8
	.align 2, 0
_0820DC98: .4byte 0x00000494
_0820DC9C: .4byte 0x000004F4
_0820DCA0: .4byte 0x00000554
_0820DCA4: .4byte 0x00000854
_0820DCA8: .4byte 0x000005B4
_0820DCAC: .4byte 0x00000D94
_0820DCB0: .4byte 0x00000E54
_0820DCB4: .4byte 0x00000D8C
_0820DCB8: .4byte 0x00000E4C
_0820DCBC: .4byte 0x00001110
_0820DCC0:
	ldr r0, [r6]
	movs r1, #0x39
	bl TextPanel_SetMessage
_0820DCC8:
	ldm r6!, {r0}
	bl TextPanel_Start
	adds r4, #2
	movs r3, #1
	add r8, r3
	cmp r8, sb
	blt _0820DC64
_0820DCD8:
	movs r3, #1
	ldr r1, [sp, #0x1c]
	movs r2, #4
_0820DCDE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820DCDE
	movs r3, #1
	mov r1, sl
	movs r2, #2
_0820DCF2:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820DCF2
	movs r5, #0
	movs r3, #0
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _0820DD86
	lsls r0, r0, #2
	ldr r1, _0820DD18 @ =_0820DD1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820DD18: .4byte _0820DD1C
_0820DD1C: @ jump table
	.4byte _0820DD40 @ case 0
	.4byte _0820DD46 @ case 1
	.4byte _0820DD4C @ case 2
	.4byte _0820DD56 @ case 3
	.4byte _0820DD5E @ case 4
	.4byte _0820DD64 @ case 5
	.4byte _0820DD6E @ case 6
	.4byte _0820DD74 @ case 7
	.4byte _0820DD7E @ case 8
_0820DD40:
	movs r1, #0
	movs r2, #0
	b _0820DD50
_0820DD46:
	movs r1, #0
	movs r2, #1
	b _0820DD50
_0820DD4C:
	movs r1, #0
	movs r2, #2
_0820DD50:
	movs r5, #0x70
	movs r3, #0x13
	b _0820DD8A
_0820DD56:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820DD8A
_0820DD5E:
	movs r1, #2
	movs r2, #0
	b _0820DD68
_0820DD64:
	movs r1, #2
	movs r2, #1
_0820DD68:
	movs r5, #0x60
	movs r3, #0x13
	b _0820DD8A
_0820DD6E:
	movs r1, #3
	movs r2, #0
	b _0820DD78
_0820DD74:
	movs r1, #3
	movs r2, #1
_0820DD78:
	movs r5, #0x80
	movs r3, #0x13
	b _0820DD8A
_0820DD7E:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820DD8A
_0820DD86:
	movs r1, #0
	movs r2, #1
_0820DD8A:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x1c]
	adds r0, r1, r0
	ldr r1, [r0]
	movs r6, #2
	rsbs r6, r6, #0
	ands r1, r6
	str r1, [r0]
	cmp r2, #0
	blt _0820DDC2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	mov r0, sl
	adds r2, r0, r1
	ldr r0, [r2]
	ands r0, r6
	str r0, [r2]
	adds r1, r7, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r5, [r0]
	ldr r0, _0820DEE4 @ =0x0000038E
	adds r1, r1, r0
	strh r3, [r1]
_0820DDC2:
	movs r1, #0
	ldr r2, [sp, #0x40]
	mov r8, r2
	movs r4, #1
_0820DDCA:
	lsls r5, r1, #1
	adds r6, r1, #1
	adds r0, r5, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820DDD8:
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DDD8
	adds r1, r5, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x28]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, r6, #0
	cmp r1, #6
	ble _0820DDCA
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x18]
	movs r3, #0
	mov sb, r3
	cmp sb, sl
	bge _0820DE6A
	ldr r0, _0820DEE8 @ =0x000005CC
	adds r5, r7, r0
	ldr r4, [sp, #0x28]
	movs r1, #0x28
	mov r8, r1
	ldr r2, _0820DEEC @ =0x0000084C
	adds r6, r7, r2
_0820DE26:
	ldr r2, [sp, #0x18]
	add r2, sb
	movs r3, #0
	str r3, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x28
	strh r0, [r5]
	mov r1, r8
	strh r1, [r5, #2]
	adds r5, #0x60
	adds r4, #0x60
	movs r2, #0x10
	add r8, r2
	adds r6, #0xc0
	movs r3, #1
	add sb, r3
	cmp sb, sl
	blt _0820DE26
_0820DE6A:
	movs r4, #1
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x30]
	movs r3, #1
_0820DE72:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DE72
	movs r4, #0
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0x98
	str r0, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0xb0
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	ldr r2, _0820DEF0 @ =0x0000125C
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0820fea8
	adds r0, r7, #0
	bl FUN_0820d138
	b _0820E06E
	.align 2, 0
_0820DEE4: .4byte 0x0000038E
_0820DEE8: .4byte 0x000005CC
_0820DEEC: .4byte 0x0000084C
_0820DEF0: .4byte 0x0000125C
_0820DEF4:
	ldr r0, [r7, #0x74]
	orrs r0, r5
	str r0, [r7, #0x74]
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820E038 @ =0x00000494
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r3, _0820E03C @ =0x000004F4
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0820E040 @ =0x00000554
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d21c
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sl, r1
	ldr r2, _0820E044 @ =0x00000854
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r3, _0820E048 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x28]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #0x3c]
	ldr r1, _0820E04C @ =0x00000D94
	adds r1, r7, r1
	str r1, [sp, #0x30]
	ldr r2, _0820E050 @ =0x00000E54
	adds r2, r7, r2
	str r2, [sp, #0x24]
	adds r3, r7, #0
	adds r3, #0x26
	str r3, [sp, #0x38]
	ldr r0, _0820E054 @ =0x0000084C
	adds r0, r0, r7
	mov sb, r0
	movs r2, #1
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r3, #4
_0820DF74:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DF74
	movs r1, #1
	mov r2, sl
	movs r3, #2
_0820DF88:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DF88
	adds r0, r7, #0
	bl FUN_0820d250
	movs r1, #0
	ldr r0, [sp, #0x40]
	mov r8, r0
	movs r6, #1
_0820DFA4:
	lsls r4, r1, #1
	adds r5, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820DFB2:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DFB2
	adds r1, r4, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x28]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r1, r5, #0
	cmp r1, #6
	ble _0820DFA4
	ldr r1, [sp, #0x38]
	ldrb r2, [r1]
	adds r2, #1
	movs r1, #0
	str r1, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r0, sb
	ldr r1, [sp, #0x3c]
	movs r3, #2
	bl FUN_082376a4
	movs r4, #1
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x30]
	movs r3, #1
_0820DFFE:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820DFFE
	ldr r2, _0820E058 @ =0x0000125C
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r3, [sp, #0x38]
	ldrb r1, [r3]
	bl FUN_0820fe98
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E05C
	ldr r0, [r4]
	bl FUN_0820feb0
	b _0820E062
	.align 2, 0
_0820E038: .4byte 0x00000494
_0820E03C: .4byte 0x000004F4
_0820E040: .4byte 0x00000554
_0820E044: .4byte 0x00000854
_0820E048: .4byte 0x000005B4
_0820E04C: .4byte 0x00000D94
_0820E050: .4byte 0x00000E54
_0820E054: .4byte 0x0000084C
_0820E058: .4byte 0x0000125C
_0820E05C:
	ldr r0, [r4]
	bl FUN_0820fea8
_0820E062:
	adds r0, r7, #0
	bl FUN_0820d188
	adds r0, r7, #0
	bl FUN_0820d138
_0820E06E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
