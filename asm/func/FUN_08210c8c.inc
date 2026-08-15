	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08210CF8 @ =0x00000D98
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08210C9C
	b _08210E82
_08210C9C:
	movs r6, #0
	movs r7, #0
	ldr r0, _08210CFC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08210CC8
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x27
	ldrb r1, [r5]
	subs r1, #1
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_0820ff14
	cmp r0, #0
	bne _08210D28
_08210CC8:
	ldr r0, _08210CFC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08210D00
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x27
	ldrb r1, [r5]
	adds r1, #1
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_0820ff14
	cmp r0, #0
	beq _08210D00
	ldrb r0, [r5]
	adds r0, #1
	b _08210D2C
	.align 2, 0
_08210CF8: .4byte 0x00000D98
_08210CFC: .4byte 0x030044E0
_08210D00:
	ldr r0, _08210D38 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08210D3C
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r0, [r5]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_0820ff14
	cmp r0, #0
	beq _08210D3C
_08210D28:
	ldrb r0, [r5]
	subs r0, #1
_08210D2C:
	strb r0, [r5]
	movs r6, #1
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08210D72
	.align 2, 0
_08210D38: .4byte 0x030044E0
_08210D3C:
	ldr r0, _08210D94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08210D72
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r0, [r5]
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	bl FUN_0820ff14
	cmp r0, #0
	beq _08210D72
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	movs r6, #1
	movs r0, #0xdc
	bl PlaySound_082406e0
_08210D72:
	ldr r0, _08210D94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08210DB6
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0
	beq _08210D98
	subs r0, #1
	b _08210D9A
	.align 2, 0
_08210D94: .4byte 0x030044E0
_08210D98:
	movs r0, #3
_08210D9A:
	strb r0, [r1]
	movs r7, #1
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r6, #1
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08210DEA
_08210DB6:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08210DEA
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #2
	bhi _08210DD0
	adds r0, #1
	strb r0, [r1]
	b _08210DD2
_08210DD0:
	strb r2, [r1]
_08210DD2:
	movs r7, #1
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r6, #1
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08210DEA:
	cmp r6, #0
	beq _08210E12
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	bl FUN_0820feec
	adds r1, r4, #0
	adds r1, #0x26
	ldrb r1, [r1]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x27
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x25
	strb r1, [r0]
_08210E12:
	cmp r7, #0
	beq _08210E36
	adds r0, r4, #0
	bl FUN_08210718
	adds r0, r4, #0
	bl FUN_08210ab0
	adds r0, r4, #0
	bl FUN_08210bb0
	adds r0, r4, #0
	bl FUN_08210610
	ldr r0, _08210E8C @ =0x00000D8A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08210E36:
	cmp r6, #0
	beq _08210E46
	adds r0, r4, #0
	bl FUN_082106a4
	adds r0, r4, #0
	bl FUN_0821053c
_08210E46:
	ldr r0, _08210E90 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08210E70
	ldr r1, _08210E94 @ =0x00000D94
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08210E62
	movs r1, #0
	bl Script_ExecById
_08210E62:
	ldr r0, _08210E98 @ =0x00000119
	bl PlaySound_082406e0
	ldr r0, _08210E9C @ =0x00000D98
	adds r1, r4, r0
	movs r0, #1
	str r0, [r1]
_08210E70:
	adds r0, r4, #0
	bl FUN_0820ffe8
	adds r0, r4, #0
	bl FUN_082106c8
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
_08210E82:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08210E8C: .4byte 0x00000D8A
_08210E90: .4byte 0x030044E0
_08210E94: .4byte 0x00000D94
_08210E98: .4byte 0x00000119
_08210E9C: .4byte 0x00000D98
