	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r7, #0
	adds r1, r7, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E084
	strb r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r1, #1
	adds r5, r0, #0
	b _0803E08A
_0803E084:
	movs r1, #0
	adds r5, r7, #0
	adds r5, #0xa7
_0803E08A:
	adds r3, r1, #0
	cmp r3, #1
	bne _0803E146
	movs r0, #4
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	ldr r2, _0803E0F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803E0F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803E0F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #8
	movs r1, #3
	ands r0, r1
	ldr r2, _0803E0FC @ =0x000002B3
	adds r1, r4, r2
	strb r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	subs r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	subs r6, #0x24
	adds r0, r4, r6
	strb r3, [r0]
	movs r0, #3
	movs r2, #0xb
	ldr r3, _0803E100 @ =0x00000818
	adds r1, r4, r3
	strb r0, [r1]
	ldr r6, _0803E104 @ =0x0000081A
	adds r0, r4, r6
	movs r3, #0
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803E10C
	ldr r0, _0803E108 @ =0x00000819
	adds r1, r4, r0
	movs r0, #0x1f
	strb r0, [r1]
	b _0803E136
	.align 2, 0
_0803E0F0: .4byte 0x030046B8
_0803E0F4: .4byte 0x000003FF
_0803E0F8: .4byte 0x0203B400
_0803E0FC: .4byte 0x000002B3
_0803E100: .4byte 0x00000818
_0803E104: .4byte 0x0000081A
_0803E108: .4byte 0x00000819
_0803E10C:
	cmp r0, #0
	bne _0803E11C
	ldr r1, _0803E118 @ =0x00000819
	adds r0, r4, r1
	b _0803E134
	.align 2, 0
_0803E118: .4byte 0x00000819
_0803E11C:
	cmp r0, #2
	bne _0803E12C
	ldr r2, _0803E128 @ =0x00000819
	adds r0, r4, r2
	b _0803E134
	.align 2, 0
_0803E128: .4byte 0x00000819
_0803E12C:
	cmp r0, #3
	bne _0803E136
	ldr r6, _0803E18C @ =0x00000819
	adds r0, r4, r6
_0803E134:
	strb r3, [r0]
_0803E136:
	ldr r0, _0803E190 @ =0x0000081E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0803E194 @ =0x000002B5
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_0803E146:
	ldrb r0, [r5]
	movs r3, #0xa3
	adds r3, r3, r7
	mov r8, r3
	cmp r0, #0
	beq _0803E154
	b _0803E2F2
_0803E154:
	ldrb r0, [r3]
	cmp r0, #5
	beq _0803E15C
	b _0803E4DC
_0803E15C:
	movs r6, #0xc8
	lsls r6, r6, #1
	mov ip, r6
	adds r3, r4, #0
	adds r3, #0x48
	mov r5, sp
	ldrb r6, [r3, #5]
	ldr r2, _0803E198 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0803E19C
	asrs r1, r0, #0xc
	b _0803E1A2
	.align 2, 0
_0803E18C: .4byte 0x00000819
_0803E190: .4byte 0x0000081E
_0803E194: .4byte 0x000002B5
_0803E198: .4byte gSineTable
_0803E19C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803E1A2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	cmp r0, #0
	blt _0803E1BE
	asrs r0, r0, #0xc
	b _0803E1C4
_0803E1BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803E1C4:
	strh r0, [r5, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r3, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #0xa]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #0xc]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0803E20A
	cmp r1, #0
	blt _0803E20A
	ldr r0, _0803E210 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803E20A
	ldr r0, _0803E214 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803E218
_0803E20A:
	movs r5, #0
	b _0803E226
	.align 2, 0
_0803E210: .4byte 0x030046A8
_0803E214: .4byte 0x030046AC
_0803E218:
	ldr r0, _0803E238 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0803E226:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0803E23C
	adds r0, #4
	b _0803E248
	.align 2, 0
_0803E238: .4byte 0x030046A4
_0803E23C:
	ldr r0, _0803E25C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803E248:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803E260
	cmp r2, #2
	beq _0803E264
	b _0803E268
	.align 2, 0
_0803E25C: .4byte 0x030046A4
_0803E260:
	ldrb r0, [r6, #4]
	b _0803E266
_0803E264:
	ldrb r0, [r6]
_0803E266:
	subs r1, r1, r0
_0803E268:
	adds r6, r1, #0
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803E292
	cmp r1, #0
	blt _0803E292
	ldr r0, _0803E298 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803E292
	ldr r0, _0803E29C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803E2A0
_0803E292:
	movs r5, #0
	b _0803E2AE
	.align 2, 0
_0803E298: .4byte 0x030046A8
_0803E29C: .4byte 0x030046AC
_0803E2A0:
	ldr r0, _0803E2C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0803E2AE:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0803E2C4
	adds r0, #4
	b _0803E2D0
	.align 2, 0
_0803E2C0: .4byte 0x030046A4
_0803E2C4:
	ldr r0, _0803E304 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803E2D0:
	ldrh r2, [r0, #2]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, r6, r0
	ldr r6, _0803E308 @ =0x000001FF
	adds r0, r0, r6
	ldr r1, _0803E30C @ =0x000002FE
	cmp r0, r1
	bhi _0803E2F2
	movs r0, #2
	ands r2, r0
	cmp r2, #0
	bne _0803E2F2
	b _0803E4DC
_0803E2F2:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #4
	beq _0803E2FE
	cmp r0, #2
	bne _0803E310
_0803E2FE:
	movs r0, #5
	b _0803E39A
	.align 2, 0
_0803E304: .4byte 0x030046A4
_0803E308: .4byte 0x000001FF
_0803E30C: .4byte 0x000002FE
_0803E310:
	cmp r0, #5
	beq _0803E316
	b _0803E444
_0803E316:
	ldr r2, _0803E350 @ =0x000002B2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803E3B0
	ldr r3, _0803E354 @ =0x000002B5
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E398
	movs r0, #1
	movs r2, #0xb
	ldr r6, _0803E358 @ =0x00000818
	adds r1, r4, r6
	strb r0, [r1]
	ldr r3, _0803E35C @ =0x0000081A
	adds r0, r4, r3
	movs r3, #0
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803E360
	adds r6, #1
	adds r1, r4, r6
	movs r0, #0x1f
	strb r0, [r1]
	b _0803E38A
	.align 2, 0
_0803E350: .4byte 0x000002B2
_0803E354: .4byte 0x000002B5
_0803E358: .4byte 0x00000818
_0803E35C: .4byte 0x0000081A
_0803E360:
	cmp r0, #0
	bne _0803E370
	ldr r1, _0803E36C @ =0x00000819
	adds r0, r4, r1
	b _0803E388
	.align 2, 0
_0803E36C: .4byte 0x00000819
_0803E370:
	cmp r0, #2
	bne _0803E380
	ldr r2, _0803E37C @ =0x00000819
	adds r0, r4, r2
	b _0803E388
	.align 2, 0
_0803E37C: .4byte 0x00000819
_0803E380:
	cmp r0, #3
	bne _0803E38A
	ldr r6, _0803E3A4 @ =0x00000819
	adds r0, r4, r6
_0803E388:
	strb r3, [r0]
_0803E38A:
	ldr r1, _0803E3A8 @ =0x0000081E
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0803E3AC @ =0x000002B5
	adds r0, r4, r2
	strb r1, [r0]
_0803E398:
	movs r0, #7
_0803E39A:
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	b _0803E4DC
	.align 2, 0
_0803E3A4: .4byte 0x00000819
_0803E3A8: .4byte 0x0000081E
_0803E3AC: .4byte 0x000002B5
_0803E3B0:
	add r0, sp, #8
	adds r1, r7, #0
	adds r1, #0x50
	movs r2, #4
	bl Map_FindNearestPathNode
	adds r3, r0, #0
	ldr r5, _0803E3EC @ =0x030046B8
	ldr r0, [r5]
	adds r1, r0, #1
	ldr r2, _0803E3F0 @ =0x000003FF
	ands r1, r2
	str r1, [r5]
	lsls r0, r1, #1
	ldr r6, _0803E3F4 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0803E3F8
	adds r0, r1, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	subs r2, r3, #2
	movs r1, #1
	ands r0, r1
	subs r3, r2, r0
	b _0803E40E
	.align 2, 0
_0803E3EC: .4byte 0x030046B8
_0803E3F0: .4byte 0x000003FF
_0803E3F4: .4byte 0x0203B400
_0803E3F8:
	adds r0, r1, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0803E43C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r3, #2
	movs r1, #1
	ands r0, r1
	adds r3, r2, r0
_0803E40E:
	movs r2, #7
	movs r6, #0xa5
	lsls r6, r6, #2
	adds r0, r4, r6
	ands r2, r3
	movs r1, #4
	bl Map_GetPathNodePos
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	ldr r2, _0803E440 @ =0x000002B2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0803E4DC
	.align 2, 0
_0803E43C: .4byte 0x0203B400
_0803E440: .4byte 0x000002B2
_0803E444:
	cmp r0, #7
	bne _0803E4DC
	ldr r3, _0803E484 @ =0x0000081E
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _0803E488 @ =0x00000819
	adds r0, r4, r6
	strb r1, [r0]
	ldr r0, _0803E48C @ =0x00000818
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	ldr r2, _0803E490 @ =0x0000081A
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0803E494
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r6, #0x83
	lsls r6, r6, #3
	adds r0, r4, r6
	b _0803E4A2
	.align 2, 0
_0803E484: .4byte 0x0000081E
_0803E488: .4byte 0x00000819
_0803E48C: .4byte 0x00000818
_0803E490: .4byte 0x0000081A
_0803E494:
	ldr r0, _0803E4D4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r1, r4, r2
_0803E4A2:
	str r0, [r1]
	movs r2, #0xf
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0803E4D8 @ =0x0000081C
	adds r0, r4, r3
	movs r1, #0
	strh r2, [r0]
	movs r6, #0xad
	lsls r6, r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	b _0803E4E6
	.align 2, 0
_0803E4D4: .4byte 0x03003584
_0803E4D8: .4byte 0x0000081C
_0803E4DC:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E4E6:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
