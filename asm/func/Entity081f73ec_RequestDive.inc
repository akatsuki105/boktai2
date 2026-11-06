	push {lr}
	ldr r0, _081F7498 @ =0x030001FC
	ldr r1, [r0]
	cmp r1, #0
	beq _081F7494
	ldr r0, _081F749C @ =0x00000722
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F7494
	cmp r0, #5
	beq _081F7494
	cmp r0, #6
	beq _081F7494
	movs r0, #5
	strb r0, [r2]
	ldr r0, _081F74A0 @ =0x00000726
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_081F7494:
	pop {r0}
	bx r0
	.align 2, 0
_081F7498: .4byte 0x030001FC
_081F749C: .4byte 0x00000722
_081F74A0: .4byte 0x00000726
