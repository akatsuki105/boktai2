	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809754A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08096fa8
	b _08097574
_0809754A:
	cmp r0, #1
	bne _08097574
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _0809757C @ =0x00003AEC
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08097580 @ =0x00003AED
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08096fa8
_08097574:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809757C: .4byte 0x00003AEC
_08097580: .4byte 0x00003AED
