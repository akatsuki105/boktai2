	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0809C3E4 @ =0x0300013C
	ldr r3, [r0]
	cmp r3, #0
	beq _0809C424
	ldr r1, _0809C3E8 @ =0x000009FE
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0809C424
	cmp r4, #0
	bge _0809C3F0
	ldr r4, _0809C3EC @ =0x00000A0E
	adds r0, r3, r4
	strh r1, [r0]
	b _0809C3F6
	.align 2, 0
_0809C3E4: .4byte 0x0300013C
_0809C3E8: .4byte 0x000009FE
_0809C3EC: .4byte 0x00000A0E
_0809C3F0:
	ldr r1, _0809C414 @ =0x00000A0E
	adds r0, r3, r1
	strh r4, [r0]
_0809C3F6:
	movs r4, #0xa1
	lsls r4, r4, #4
	adds r0, r3, r4
	strh r5, [r0]
	ldr r0, _0809C418 @ =0x00000A12
	adds r1, r3, r0
	movs r0, #0xb4
	strh r0, [r1]
	cmp r2, #0
	beq _0809C41C
	adds r4, #4
	adds r1, r3, r4
	movs r0, #6
	b _0809C422
	.align 2, 0
_0809C414: .4byte 0x00000A0E
_0809C418: .4byte 0x00000A12
_0809C41C:
	ldr r0, _0809C42C @ =0x00000A14
	adds r1, r3, r0
	movs r0, #0
_0809C422:
	strb r0, [r1]
_0809C424:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C42C: .4byte 0x00000A14
