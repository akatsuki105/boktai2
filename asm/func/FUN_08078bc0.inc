	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08078BF4
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08060c50
	cmp r0, #0
	bne _08078BF2
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _08078BF4
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
_08078BF2:
	str r4, [r5, #0x3c]
_08078BF4:
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C20
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08078C3E
_08078C20:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08078C58 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08078C3E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C5C
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08078C68
	.align 2, 0
_08078C58: .4byte 0x0000FFFB
_08078C5C:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08078C68:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08060c50
	cmp r0, #0
	beq _08078C82
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _08078C88
_08078C82:
	ldr r0, [r4]
	ldr r1, _08078CA4 @ =0xFFFFFDFF
	ands r0, r1
_08078C88:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08078CA8
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08078CB2
	.align 2, 0
_08078CA4: .4byte 0xFFFFFDFF
_08078CA8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08078CB2:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08078CD0
	ldr r1, _08078CCC @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08078CD8
	.align 2, 0
_08078CCC: .4byte 0x0000060C
_08078CD0:
	ldr r2, _08078D44 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08078CD8:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	adds r4, r5, #0
	adds r4, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r4]
	str r1, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _08078D48 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08078D4C @ =0x0000044B
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _08078D3C
	ldr r2, _08078D50 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08078D54 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08078D58 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	subs r1, #7
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r2, r5, #0
	adds r2, #0xac
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
_08078D3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08078D44: .4byte 0x0000060C
_08078D48: .4byte 0x000003F6
_08078D4C: .4byte 0x0000044B
_08078D50: .4byte 0x030046B8
_08078D54: .4byte 0x000003FF
_08078D58: .4byte 0x0203B400
