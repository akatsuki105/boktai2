	push {lr}
	ldr r0, _0800272C @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	beq _08002730
	adds r0, #0x20
	ldrb r0, [r0]
	b _08002732
	.align 2, 0
_0800272C: .4byte gEntity4AE5
_08002730:
	movs r0, #0
_08002732:
	pop {r1}
	bx r1
	.align 2, 0
