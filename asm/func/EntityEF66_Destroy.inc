	ldr r0, _080A1490 @ =0x03002B84
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080A1494 @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080A1498 @ =0x03002B90
	strh r1, [r0]
	ldr r1, _080A149C @ =0x03000148
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A1490: .4byte 0x03002B84
_080A1494: .4byte 0x03002BAC
_080A1498: .4byte 0x03002B90
_080A149C: .4byte 0x03000148
