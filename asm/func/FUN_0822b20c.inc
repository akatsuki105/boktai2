	push {lr}
	adds r2, r0, #0
	ldr r0, _0822B22C @ =0x03003580
	ldrh r0, [r0]
	cmp r1, r0
	bge _0822B226
	strh r1, [r2, #6]
	ldr r0, _0822B230 @ =0x03003584
	ldrh r1, [r2, #6]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0xc]
_0822B226:
	pop {r0}
	bx r0
	.align 2, 0
_0822B22C: .4byte 0x03003580
_0822B230: .4byte 0x03003584
