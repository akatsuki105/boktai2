	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_081e0ec0
	adds r0, r4, #0
	bl FUN_081e0c20
	ldrh r1, [r4, #0x10]
	ldr r0, _081E1110 @ =0xFFFFFF00
	adds r5, r0, #0
	ands r5, r1
	strh r5, [r4, #0x10]
	ldrh r1, [r4, #0x14]
	ands r0, r1
	strh r0, [r4, #0x14]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _081E1120
	ldr r3, _081E1114 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081E1118 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081E111C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x80
	movs r2, #0x7f
	ands r0, r2
	adds r1, r1, r0
	strh r1, [r4, #0x10]
	adds r2, r3, #0
	b _081E113C
	.align 2, 0
_081E1110: .4byte 0xFFFFFF00
_081E1114: .4byte 0x030046B8
_081E1118: .4byte 0x000003FF
_081E111C: .4byte 0x0203B400
_081E1120:
	ldr r2, _081E1158 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, r5, r0
	strh r0, [r4, #0x10]
_081E113C:
	cmp r6, #2
	bgt _081E1164
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	lsls r0, r6, #2
	adds r0, r0, r6
	b _081E117C
	.align 2, 0
_081E1158: .4byte 0x030046B8
_081E115C: .4byte 0x000003FF
_081E1160: .4byte 0x0203B400
_081E1164:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E11B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E11BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	subs r1, r6, #3
	lsls r0, r1, #2
	adds r0, r0, r1
_081E117C:
	lsls r0, r0, #4
	movs r1, #0x3f
	ands r2, r1
	adds r0, r0, r2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
	strh r0, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x10
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E11B2
	cmp r1, #0
	blt _081E11B2
	ldr r0, _081E11C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E11B2
	ldr r0, _081E11C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E11C8
_081E11B2:
	movs r5, #0
	b _081E11D6
	.align 2, 0
_081E11B8: .4byte 0x000003FF
_081E11BC: .4byte 0x0203B400
_081E11C0: .4byte 0x030046A8
_081E11C4: .4byte 0x030046AC
_081E11C8:
	ldr r0, _081E11E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081E11D6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081E11EC
	adds r0, #4
	b _081E11F8
	.align 2, 0
_081E11E8: .4byte 0x030046A4
_081E11EC:
	ldr r0, _081E120C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E11F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E1210
	cmp r2, #2
	beq _081E1214
	b _081E1218
	.align 2, 0
_081E120C: .4byte 0x030046A4
_081E1210:
	ldrb r0, [r6, #4]
	b _081E1216
_081E1214:
	ldrb r0, [r6]
_081E1216:
	subs r1, r1, r0
_081E1218:
	strh r1, [r4, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
