	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804BFC4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804BFA0
	b _0804C184
_0804BFA0:
	cmp r3, #0x33
	bne _0804BFA6
	b _0804C0C4
_0804BFA6:
	cmp r3, #0x33
	bgt _0804BFE6
	cmp r3, #0x13
	beq _0804C058
	cmp r3, #0x13
	bgt _0804BFCE
	cmp r3, #0x10
	bne _0804BFB8
	b _0804C184
_0804BFB8:
	cmp r3, #0x10
	bgt _0804BFC8
	cmp r3, #0
	beq _0804C036
	b _0804C184
	.align 2, 0
_0804BFC4: .4byte 0x03002B58
_0804BFC8:
	cmp r3, #0x11
	beq _0804C046
	b _0804C184
_0804BFCE:
	cmp r3, #0x30
	beq _0804C0C4
	cmp r3, #0x30
	bgt _0804BFDC
	cmp r3, #0x14
	beq _0804C06A
	b _0804C184
_0804BFDC:
	cmp r3, #0x31
	beq _0804C09A
	cmp r3, #0x32
	beq _0804C0B0
	b _0804C184
_0804BFE6:
	cmp r3, #0x44
	bne _0804BFEC
	b _0804C148
_0804BFEC:
	cmp r3, #0x44
	bgt _0804C010
	cmp r3, #0x41
	bne _0804BFF6
	b _0804C184
_0804BFF6:
	cmp r3, #0x41
	bgt _0804C002
	cmp r3, #0x40
	bne _0804C000
	b _0804C0F4
_0804C000:
	b _0804C184
_0804C002:
	cmp r3, #0x42
	bne _0804C008
	b _0804C124
_0804C008:
	cmp r3, #0x43
	bne _0804C00E
	b _0804C136
_0804C00E:
	b _0804C184
_0804C010:
	cmp r3, #0xf1
	bne _0804C016
	b _0804C166
_0804C016:
	cmp r3, #0xf1
	bgt _0804C028
	cmp r3, #0x50
	bne _0804C020
	b _0804C17E
_0804C020:
	cmp r3, #0xf0
	bne _0804C026
	b _0804C166
_0804C026:
	b _0804C184
_0804C028:
	cmp r3, #0xf2
	bne _0804C02E
	b _0804C166
_0804C02E:
	cmp r3, #0xff
	bne _0804C034
	b _0804C15A
_0804C034:
	b _0804C184
_0804C036:
	movs r0, #5
	strb r3, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r3, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C046:
	ldr r0, _0804C054 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r4, #0x19]
	orrs r0, r1
	strb r0, [r4, #0x19]
	b _0804C184
	.align 2, 0
_0804C054: .4byte 0x03004740
_0804C058:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C06A:
	ldr r0, _0804C084 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #1]
	cmp r1, #0
	bne _0804C088
	movs r0, #5
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C084: .4byte 0x03005800
_0804C088:
	movs r1, #9
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C09A:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0AC @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0AC: .4byte 0x03004740
_0804C0B0:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0C0: .4byte 0x03004740
_0804C0C4:
	ldr r2, _0804C0F0 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C0F0: .4byte 0x03004740
_0804C0F4:
	ldr r2, _0804C120 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C120: .4byte 0x03004740
_0804C124:
	movs r1, #0x20
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C136:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C148:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C15A:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
	cmp r0, #1
	bls _0804C17E
	b _0804C16C
_0804C166:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
_0804C16C:
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C17E:
	ldr r1, _0804C18C @ =0x030000DC
	movs r0, #0
_0804C182:
	strb r0, [r1]
_0804C184:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C18C: .4byte 0x030000DC
