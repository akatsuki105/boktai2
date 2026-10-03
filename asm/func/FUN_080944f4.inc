	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809450E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _08094550
_0809450E:
	cmp r0, #1
	bne _08094550
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0809452C @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094530
	movs r0, #0
	bl SortInventory
	b _08094536
	.align 2, 0
_0809452C: .4byte 0x00003F9C
_08094530:
	movs r0, #0
	bl SortValuable
_08094536:
	ldr r2, _08094558 @ =0x00003AEC
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08092744
_08094550:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094558: .4byte 0x00003AEC
