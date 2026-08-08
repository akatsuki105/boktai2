	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	bne _0824101C
	lsls r0, r2, #7
	adds r0, r0, r2
	adds r0, #0x11
	b _08241028
_0824101C:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r0, r0, r2
	ldr r1, _0824102C @ =0x00000113
	adds r0, r0, r1
_08241028:
	pop {r1}
	bx r1
	.align 2, 0
_0824102C: .4byte 0x00000113
