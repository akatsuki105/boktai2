	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #8]
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r6, r1, #6
	adds r0, r6, #2
	str r0, [sp, #0xc]
	movs r0, #3
	ldr r1, [sp, #0xc]
	ands r1, r0
	str r1, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
_0817BC9A:
	ldr r3, [sp, #0xc]
	cmp r6, r3
	bne _0817BCA2
	b _0817C000
_0817BCA2:
	cmp r6, #1
	beq _0817BCCC
	cmp r6, #1
	bgt _0817BCB0
	cmp r6, #0
	beq _0817BCBA
	b _0817BD20
_0817BCB0:
	cmp r6, #2
	beq _0817BCEC
	cmp r6, #3
	beq _0817BD00
	b _0817BD20
_0817BCBA:
	ldr r0, [sp, #8]
	ldr r2, _0817BCC8 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r7, r0, #1
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCC8: .4byte 0x00000256
_0817BCCC:
	ldr r3, [sp, #8]
	ldr r0, _0817BCE4 @ =0x00000256
	adds r1, r3, r0
	ldr r2, _0817BCE8 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCE4: .4byte 0x00000256
_0817BCE8: .4byte 0x030046A4
_0817BCEC:
	ldr r3, [sp, #8]
	ldr r0, _0817BCFC @ =0x00000256
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r7, r0, #1
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BCFC: .4byte 0x00000256
_0817BD00:
	ldr r2, [sp, #8]
	ldr r3, _0817BD18 @ =0x00000256
	adds r1, r2, r3
	ldrh r2, [r1]
	ldr r3, _0817BD1C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov r8, r1
	b _0817BD2A
	.align 2, 0
_0817BD18: .4byte 0x00000256
_0817BD1C: .4byte 0x030046A4
_0817BD20:
	ldr r1, [sp, #8]
	ldr r2, _0817BD3C @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	mov r8, r0
_0817BD2A:
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BD40
	adds r0, #4
	b _0817BD4C
	.align 2, 0
_0817BD3C: .4byte 0x00000256
_0817BD40:
	ldr r3, _0817BD68 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BD4C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x14]
	mov r0, r8
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BD6C
	adds r0, #4
	b _0817BD78
	.align 2, 0
_0817BD68: .4byte 0x030046A4
_0817BD6C:
	ldr r1, _0817BD90 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BD78:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BD94
	adds r0, #4
	b _0817BDA0
	.align 2, 0
_0817BD90: .4byte 0x030046A4
_0817BD94:
	ldr r2, _0817BDE0 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BDA0:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x1c]
	mov sl, sp
	ldr r5, _0817BDE0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BDE4
	adds r0, #4
	b _0817BDEE
	.align 2, 0
_0817BDE0: .4byte 0x030046A4
_0817BDE4:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BDEE:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sl
	strh r1, [r3, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BE14
	adds r0, #4
	b _0817BE20
_0817BE14:
	ldr r2, _0817BE38 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BE20:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817BE3C
	cmp r2, #2
	beq _0817BE40
	b _0817BE44
	.align 2, 0
_0817BE38: .4byte 0x030046A4
_0817BE3C:
	ldrb r0, [r4, #4]
	b _0817BE42
_0817BE40:
	ldrb r0, [r4]
_0817BE42:
	subs r1, r1, r0
_0817BE44:
	str r1, [sp, #0x20]
	mov r0, r8
	ldrh r5, [r0]
	mov sl, sp
	ldr r1, _0817BE88 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0817BE88 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BE8C
	adds r0, #4
	b _0817BE98
	.align 2, 0
_0817BE88: .4byte 0x030046A4
_0817BE8C:
	ldr r3, _0817BEC4 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BE98:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r0, sl
	strh r1, [r0, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
	mov r3, r8
	ldrh r4, [r3]
	mov r5, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0817BEC8
	adds r0, #4
	b _0817BED4
	.align 2, 0
_0817BEC4: .4byte 0x030046A4
_0817BEC8:
	ldr r1, _0817BEEC @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0817BED4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0817BEF0
	cmp r2, #2
	beq _0817BEF4
	b _0817BEF8
	.align 2, 0
_0817BEEC: .4byte 0x030046A4
_0817BEF0:
	ldrb r0, [r5, #4]
	b _0817BEF6
_0817BEF4:
	ldrb r0, [r5]
_0817BEF6:
	subs r1, r1, r0
_0817BEF8:
	ldr r0, [sp, #0x20]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x20]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _0817C000
	cmp r2, #0
	beq _0817BFFA
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0817BF36
	cmp r6, #1
	bne _0817BF30
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0817BF4C
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BF5A
_0817BF30:
	cmp r6, #3
	bne _0817C000
	b _0817BF56
_0817BF36:
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0817BF5E
	cmp r6, #0
	bne _0817BF52
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0817BF4C
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BF5A
_0817BF4C:
	cmp r1, #0
	beq _0817BF5E
	b _0817C000
_0817BF52:
	cmp r6, #2
	bne _0817C000
_0817BF56:
	ldr r3, [sp, #0x18]
	ldr r0, _0817BF74 @ =0xFFFFFF00
_0817BF5A:
	cmp r1, r0
	bne _0817C000
_0817BF5E:
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne _0817BF84
	cmp r6, #1
	bne _0817BF78
	ldr r3, [sp, #0x14]
	cmp r3, #1
	bne _0817BF94
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BFB0
	.align 2, 0
_0817BF74: .4byte 0xFFFFFF00
_0817BF78:
	cmp r6, #3
	bne _0817C000
	ldr r0, [sp, #0x14]
	cmp r0, #1
	beq _0817BFAE
	b _0817BFBC
_0817BF84:
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0817BFCC
	cmp r6, #0
	bne _0817BFA4
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0817BF9E
_0817BF94:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _0817BFC0
	b _0817C000
_0817BF9E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _0817BFB0
_0817BFA4:
	cmp r6, #2
	bne _0817C000
	ldr r3, [sp, #0x14]
	cmp r3, #2
	bne _0817BFBC
_0817BFAE:
	ldr r0, _0817BFB8 @ =0xFFFFFF00
_0817BFB0:
	cmp r1, r0
	beq _0817BFC0
	b _0817C000
	.align 2, 0
_0817BFB8: .4byte 0xFFFFFF00
_0817BFBC:
	cmp r1, #0
	bne _0817C000
_0817BFC0:
	ldr r0, [sp, #0x18]
	cmp r0, #2
	bne _0817BFCC
	ldr r1, [sp, #0x14]
	cmp r1, #2
	beq _0817BFD8
_0817BFCC:
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0817BFEA
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0817BFEA
_0817BFD8:
	adds r0, r2, #0
	cmp r2, #0
	bge _0817BFE0
	rsbs r0, r2, #0
_0817BFE0:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0817BFFA
	b _0817C000
_0817BFEA:
	adds r0, r2, #0
	cmp r0, #0
	bge _0817BFF2
	rsbs r0, r0, #0
_0817BFF2:
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0xff
	bgt _0817BFFC
_0817BFFA:
	adds r1, r7, #0
_0817BFFC:
	cmp r1, #0
	bge _0817C008
_0817C000:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0817C00C
_0817C008:
	adds r0, r6, #0
	b _0817C01C
_0817C00C:
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	cmp r2, #3
	bgt _0817C018
	b _0817BC9A
_0817C018:
	movs r0, #1
	rsbs r0, r0, #0
_0817C01C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
