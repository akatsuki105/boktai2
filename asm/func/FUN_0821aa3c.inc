	push {lr}
	adds r2, r0, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	bne _0821AA82
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AA58
	asrs r1, r0, #0x10
	b _0821AA5E
_0821AA58:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821AA5E:
	adds r0, r2, #0
	adds r0, #0x58
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AA74
	asrs r1, r0, #0x10
	b _0821AA7A
_0821AA74:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821AA7A:
	adds r0, r2, #0
	adds r0, #0x5a
	strh r1, [r0]
	b _0821AABC
_0821AA82:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AA92
	asrs r1, r0, #0x10
	b _0821AA98
_0821AA92:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821AA98:
	adds r0, r2, #0
	adds r0, #0xb4
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821AAAE
	asrs r0, r0, #0x10
	b _0821AAB4
_0821AAAE:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821AAB4:
	adds r1, r2, #0
	adds r1, #0xb6
	subs r0, #0xf
	strh r0, [r1]
_0821AABC:
	pop {r0}
	bx r0
