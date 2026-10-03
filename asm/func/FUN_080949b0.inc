	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08094A74 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _08094A78 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _08094A7C @ =0x00003F9C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #6
	bl FUN_0808a3c4
	bl FUN_08094988
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08094A80 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08094A84 @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094A88 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08094838
	adds r0, r4, #0
	bl FUN_08094780
	bl FUN_08049f5c
	ldr r0, _08094A8C @ =0x0000EFDA
	bl TextBox_SetBgPltt
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _08094A90 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094A74: .4byte 0x00004014
_08094A78: .4byte 0x00004018
_08094A7C: .4byte 0x00003F9C
_08094A80: .4byte 0x00000F56
_08094A84: .4byte 0x0000156C
_08094A88: .4byte 0x00001564
_08094A8C: .4byte 0x0000EFDA
_08094A90: .4byte FUN_08094070
