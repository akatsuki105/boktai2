	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _080960E2
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08095a5c
	b _0809610C
_080960E2:
	cmp r0, #1
	bne _0809610C
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _08096114 @ =0x00003AEC
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08096118 @ =0x00003AED
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08095a5c
_0809610C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096114: .4byte 0x00003AEC
_08096118: .4byte 0x00003AED
