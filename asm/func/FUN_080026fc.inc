	push {lr}
	adds r1, r0, #0
	ldr r0, _08002714 @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	beq _0800270E
	ldr r2, _08002718 @ =0x00000644
	adds r0, r0, r2
	strb r1, [r0]
_0800270E:
	pop {r0}
	bx r0
	.align 2, 0
_08002714: .4byte gEntity4AE5
_08002718: .4byte 0x00000644
