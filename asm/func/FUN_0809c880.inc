	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C8E0
	adds r1, #0x1e
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0809C8E0
	cmp r0, #2
	bhi _0809C8E0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	movs r2, #9
	movs r3, #0x12
	bl FUN_0809c780
	adds r0, r4, #0
	bl FUN_0808afac
	adds r0, r4, #0
	bl FUN_0808ad5c
	adds r0, r4, #0
	bl FUN_0809c668
	adds r0, r4, #0
	bl FUN_0809c70c
	adds r0, r4, #0
	bl FUN_0808b1bc
_0809C8E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
