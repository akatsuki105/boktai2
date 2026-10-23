	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E5EF4 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E5DE0
	b _081E5FA8
_081E5DE0:
	bl Marquee_Clear
	bl FUN_08049f84
	ldr r2, _081E5EF8 @ =0x00001610
	adds r2, r2, r7
	mov r8, r2
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E5EFC @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E5F00 @ =0x00001608
	adds r6, r7, r0
	ldr r0, [r6]
	bl TextPanel_Hide
	ldr r1, _081E5F04 @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl TextPanel_Hide
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl Video_SetBGLayer
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081E5F08 @ =0x000015F0
	adds r2, r2, r7
	mov sb, r2
	ldr r1, [r2]
	bl TextPanel_SetScript
	adds r0, r7, #0
	bl FUN_081e2e24
	ldr r1, _081E5F0C @ =0x00000E28
	adds r0, r7, r1
	ldr r2, _081E5F10 @ =0x0000159C
	adds r5, r7, r2
	adds r1, r5, #0
	bl FUN_08094c6c
	ldr r0, [r4]
	ldr r2, _081E5F14 @ =0x000015E2
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	ldr r1, _081E5F18 @ =0x000015A4
	adds r2, r7, r1
	movs r1, #3
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	adds r2, r5, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E5F1C @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r6]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r6]
	mov r2, sb
	ldr r1, [r2]
	bl TextPanel_SetScript
	ldr r0, [r6]
	movs r1, #0x12
	bl TextPanel_SetMessage
	ldr r0, [r6]
	bl TextPanel_Start
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5F20
	movs r0, #1
	b _081E5F22
	.align 2, 0
_081E5EF4: .4byte 0x00001614
_081E5EF8: .4byte 0x00001610
_081E5EFC: .4byte 0x00001604
_081E5F00: .4byte 0x00001608
_081E5F04: .4byte 0x0000160C
_081E5F08: .4byte 0x000015F0
_081E5F0C: .4byte 0x00000E28
_081E5F10: .4byte 0x0000159C
_081E5F14: .4byte 0x000015E2
_081E5F18: .4byte 0x000015A4
_081E5F1C: .4byte 0x00000BB8
_081E5F20:
	movs r0, #0
_081E5F22:
	cmp r0, #0
	beq _081E5F5C
	ldr r1, _081E5F40 @ =0x000015E2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F48
	ldr r2, _081E5F44 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc
	bl TextPanel_SetMessage
	b _081E5F88
	.align 2, 0
_081E5F40: .4byte 0x000015E2
_081E5F44: .4byte 0x0000160C
_081E5F48:
	ldr r1, _081E5F58 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x17
	bl TextPanel_SetMessage
	b _081E5F88
	.align 2, 0
_081E5F58: .4byte 0x0000160C
_081E5F5C:
	ldr r2, _081E5F74 @ =0x000015E2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F7C
	ldr r1, _081E5F78 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xd
	bl TextPanel_SetMessage
	b _081E5F88
	.align 2, 0
_081E5F74: .4byte 0x000015E2
_081E5F78: .4byte 0x0000160C
_081E5F7C:
	ldr r2, _081E5FC0 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x18
	bl TextPanel_SetMessage
_081E5F88:
	ldr r1, _081E5FC0 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextPanel_Start
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	ldr r0, _081E5FC4 @ =0x00000123
	bl PlaySound_082406e0
	ldr r2, _081E5FC8 @ =0x00001614
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081E5FA8:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5FCC @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E5FD0
	movs r0, #1
	b _081E5FD2
	.align 2, 0
_081E5FC0: .4byte 0x0000160C
_081E5FC4: .4byte 0x00000123
_081E5FC8: .4byte 0x00001614
_081E5FCC: .4byte 0x00001610
_081E5FD0:
	movs r0, #0
_081E5FD2:
	cmp r0, #0
	beq _081E5FE0
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	b _081E6022
_081E5FE0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5FF0
	movs r0, #1
	b _081E5FF2
_081E5FF0:
	movs r0, #0
_081E5FF2:
	cmp r0, #0
	beq _081E6022
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #7
	bne _081E6022
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6022
	ldr r0, _081E6030 @ =FUN_081e603c
	movs r2, #0xf
	str r0, [r7, #0x18]
	ldr r0, _081E6034 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6038 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E6022:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E6030: .4byte FUN_081e603c
_081E6034: .4byte 0x00001614
_081E6038: .4byte 0x00001616
