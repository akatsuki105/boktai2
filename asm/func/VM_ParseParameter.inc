	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	beq _082314A0
	ldr r0, _0823149C @ =gVM
	ldr r0, [r0, #0x6c]
	subs r0, #4
	ldr r0, [r0]
	ldr r1, [r0, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	subs r0, #4
	ldr r0, [r0]
	b _082314A4
	.align 2, 0
_0823149C: .4byte gVM
_082314A0:
	ldr r0, _082314A8 @ =gVM
	ldr r0, [r0, #4]
_082314A4:
	pop {r1}
	bx r1
	.align 2, 0
_082314A8: .4byte gVM
