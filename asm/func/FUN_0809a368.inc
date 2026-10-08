	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A39C
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A398 @ =FUN_0809a324
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	b _0809A3E8
	.align 2, 0
_0809A398: .4byte FUN_0809a324
_0809A39C:
	cmp r0, #1
	bne _0809A3E8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r0, _0809A3C4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809A3C8 @ =0x0000093A
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0809A3D0
	ldr r1, _0809A3CC @ =FUN_0809a448
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _0809A3E8
	.align 2, 0
_0809A3C4: .4byte 0x030046A0
_0809A3C8: .4byte 0x0000093A
_0809A3CC: .4byte FUN_0809a448
_0809A3D0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	movs r0, #0xa
	bl FUN_08099b3c
	ldr r1, _0809A3F0 @ =FUN_0809a3f4
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
_0809A3E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A3F0: .4byte FUN_0809a3f4
