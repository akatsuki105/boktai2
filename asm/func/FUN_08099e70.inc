	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08099EB0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08099b9c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	movs r0, #7
	bl FUN_08099b3c
	ldr r1, _08099EAC @ =FUN_08099f18
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _08099F0E
	.align 2, 0
_08099EA8: .4byte 0x030044E0
_08099EAC: .4byte FUN_08099f18
_08099EB0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08099c1c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	movs r0, #5
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099EEC @ =FUN_08099e2c
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	b _08099F0E
	.align 2, 0
_08099EEC: .4byte FUN_08099e2c
_08099EF0:
	adds r0, r4, #0
	bl FUN_08099d2c
	cmp r0, #0
	beq _08099F02
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08099c64
_08099F02:
	ldr r1, _08099F14 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
_08099F0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099F14: .4byte 0x00001444
