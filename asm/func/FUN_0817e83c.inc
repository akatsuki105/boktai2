	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r2, _0817E85C @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E860
	movs r0, #1
	b _0817E862
	.align 2, 0
_0817E85C: .4byte 0x00000898
_0817E860:
	movs r0, #0
_0817E862:
	cmp r0, #0
	bne _0817E86A
	movs r0, #0
	b _0817E86C
_0817E86A:
	movs r0, #1
_0817E86C:
	pop {r1}
	bx r1
