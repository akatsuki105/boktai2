	push {lr}
	ldr r0, _0822B25C @ =0x03003578
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0822B260 @ =0x0300357C
	strh r1, [r0]
	ldr r2, _0822B264 @ =0x03003588
	strh r1, [r2]
	ldr r0, _0822B268 @ =0x0300358C
	ldr r0, [r0]
	cmp r0, #0
	beq _0822B256
	ldr r0, _0822B26C @ =0x03003594
	ldrh r0, [r0]
	strh r0, [r2]
_0822B256:
	pop {r0}
	bx r0
	.align 2, 0
_0822B25C: .4byte 0x03003578
_0822B260: .4byte 0x0300357C
_0822B264: .4byte 0x03003588
_0822B268: .4byte 0x0300358C
_0822B26C: .4byte 0x03003594
