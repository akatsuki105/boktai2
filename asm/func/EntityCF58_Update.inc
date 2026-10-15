	push {lr}
	adds r2, r0, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _080A601C
	adds r0, r2, #0
	bl KillEntity
	b _080A6028
_080A601C:
	adds r0, r2, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_080A6028:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
