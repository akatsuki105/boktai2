	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r1, _0819DD38 @ =gSineTable
	ldr r2, _0819DD3C @ =0x00000EA6
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0819DD40
	asrs r2, r0, #0xc
	b _0819DD46
	.align 2, 0
_0819DD38: .4byte gSineTable
_0819DD3C: .4byte 0x00000EA6
_0819DD40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0819DD46:
	ldr r0, _0819DD6C @ =0x03002BE0
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xdc
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	ldr r2, _0819DD70 @ =0x00000A7E
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _0819DD74 @ =0x00000EA6
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819DD6C: .4byte 0x03002BE0
_0819DD70: .4byte 0x00000A7E
_0819DD74: .4byte 0x00000EA6
