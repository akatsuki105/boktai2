	push {r4, lr}
	ldr r3, _0822A148 @ =0x03000250
	ldr r0, [r3]
	cmp r0, #0
	bne _0822A154
	ldr r0, _0822A14C @ =0x03002CEC
	ldr r0, [r0]
	cmp r0, #0
	beq _0822A140
	ldr r2, _0822A150 @ =0x04000004
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r4, #0x90
	lsls r4, r4, #8
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	str r0, [r3]
_0822A140:
	bl m4aSoundMain
	b _0822A176
	.align 2, 0
_0822A148: .4byte 0x03000250
_0822A14C: .4byte 0x03002CEC
_0822A150: .4byte 0x04000004
_0822A154:
	ldr r2, _0822A17C @ =0x04000010
	ldr r0, _0822A180 @ =0x03003508
	movs r1, #0xff
	ldrb r0, [r0]
	strh r0, [r2]
	subs r2, #0xc
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	str r0, [r3]
_0822A176:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822A17C: .4byte 0x04000010
_0822A180: .4byte 0x03003508
