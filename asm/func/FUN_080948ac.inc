	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0809496C @ =0x00003F9C
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08094970 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _08094974 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
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
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08094978 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _0809497C @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094980 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x9d
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08094838
	adds r0, r4, #0
	bl FUN_08094780
	adds r0, r4, #0
	bl FUN_080923a0
	bl FUN_08049f5c
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _08094984 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809496C: .4byte 0x00003F9C
_08094970: .4byte 0x00004014
_08094974: .4byte 0x00004018
_08094978: .4byte 0x00000F56
_0809497C: .4byte 0x0000156C
_08094980: .4byte 0x00001564
_08094984: .4byte FUN_08094070
