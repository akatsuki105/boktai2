	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, _0801F830 @ =0x085AA9FC
	movs r0, #0x39
	adds r0, r0, r4
	mov ip, r0
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	strb r0, [r4, #7]
	ldrb r0, [r2]
	cmp r0, #1
	bls _0801F826
	cmp r0, #4
	beq _0801F826
	cmp r0, #5
	bne _0801F834
_0801F826:
	ldr r0, [r4, #0x70]
	ldr r1, [r4, #0x74]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	b _0801F852
	.align 2, 0
_0801F830: .4byte 0x085AA9FC
_0801F834:
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0x5a
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x20]
_0801F852:
	pop {r4, r5}
	pop {r0}
	bx r0
