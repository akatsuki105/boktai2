	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	bne _080AB058
	movs r1, #1
	movs r2, #0xe1
	lsls r2, r2, #3
	ldr r0, _080AB04C @ =0x03002B80
	movs r3, #1
	strh r1, [r0]
	ldr r0, _080AB050 @ =0x03002B78
	strh r2, [r0]
	ldr r1, _080AB054 @ =0x03002BF0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strb r3, [r4, #0x19]
	b _080AB066
	.align 2, 0
_080AB04C: .4byte 0x03002B80
_080AB050: .4byte 0x03002B78
_080AB054: .4byte 0x03002BF0
_080AB058:
	movs r1, #2
	movs r2, #0xe1
	lsls r2, r2, #3
	ldr r0, _080AB06C @ =0x03002B80
	strh r1, [r0]
	ldr r0, _080AB070 @ =0x03002B78
	strh r2, [r0]
_080AB066:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AB06C: .4byte 0x03002B80
_080AB070: .4byte 0x03002B78
