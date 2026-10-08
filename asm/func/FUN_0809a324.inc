	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809A360 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809A358
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	movs r0, #9
	bl FUN_08099b3c
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _0809A364 @ =FUN_0809a368
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
_0809A358:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A360: .4byte 0x030044E0
_0809A364: .4byte FUN_0809a368
