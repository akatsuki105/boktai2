	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _08077CE0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08077CD4
	b _08077FF2
_08077CD4:
	lsls r0, r0, #2
	ldr r1, _08077CE4 @ =_08077CE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077CE0: .4byte 0x0000037D
_08077CE4: .4byte _08077CE8
_08077CE8: @ jump table
	.4byte _08077D00 @ case 0
	.4byte _08077D38 @ case 1
	.4byte _08077DE8 @ case 2
	.4byte _08077F10 @ case 3
	.4byte _08077F8C @ case 4
	.4byte _08077FC4 @ case 5
_08077D00:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077D2C
	b _08077FF2
_08077D2C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08077FF2
_08077D38:
	ldr r2, _08077DC8 @ =0x0000037E
	adds r5, r4, r2
	ldrh r2, [r5]
	cmp r2, #0
	bne _08077D66
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08077DCC @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08077DD0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08077D66:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08077D8E
	b _08077FF2
_08077D8E:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077DA8
	b _08077F4C
_08077DA8:
	movs r0, #0x10
	ldr r1, [r4, #0x20]
	ands r1, r0
	cmp r1, #0
	beq _08077DDC
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r0, _08077DD4 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08077DD8 @ =0x00000404
	adds r1, r4, r2
	b _08077F74
	.align 2, 0
_08077DC8: .4byte 0x0000037E
_08077DCC: .4byte 0x000002E6
_08077DD0: .4byte 0x000002E7
_08077DD4: .4byte 0x00000409
_08077DD8: .4byte 0x00000404
_08077DDC:
	ldr r2, _08077DE4 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _08077E8A
	.align 2, 0
_08077DE4: .4byte 0x00000404
_08077DE8:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _08077E6C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08077E1A
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _08077E1A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08077E1A
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08077E1A:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r6, #0
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08061f6c
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08077E74
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08077E70 @ =0x00000409
	adds r0, r4, r2
	strb r6, [r0]
	b _08077F4C
	.align 2, 0
_08077E6C: .4byte 0x00000404
_08077E70: .4byte 0x00000409
_08077E74:
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08077E9C
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _08077E98 @ =0x00000409
	adds r0, r4, r1
	strb r6, [r0]
_08077E8A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _08077FF2
	.align 2, 0
_08077E98: .4byte 0x00000409
_08077E9C:
	ldr r0, _08077F00 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08077F04 @ =0x00000942
	adds r0, r0, r2
	ldr r2, _08077F08 @ =0x00000436
	adds r1, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08077EC4
	b _08077FF2
_08077EC4:
	bl FUN_0809c58c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r3, [r2]
	cmp r3, #0
	bne _08077EE0
	b _08077FF2
_08077EE0:
	ldr r1, _08077F0C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	movs r0, #0
	str r0, [r2]
	adds r0, r3, #0
	bl FUN_082318ac
	b _08077FF2
	.align 2, 0
_08077F00: .4byte 0x030046A0
_08077F04: .4byte 0x00000942
_08077F08: .4byte 0x00000436
_08077F0C: .4byte 0xFFFF0000
_08077F10:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08077F58
_08077F4C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08077FF2
_08077F58:
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08077FF2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08077F84 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08077F88 @ =0x00000404
	adds r1, r4, r0
_08077F74:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08077FF2
	.align 2, 0
_08077F84: .4byte 0x00000409
_08077F88: .4byte 0x00000404
_08077F8C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08077FF2
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	b _08077FF2
_08077FC4:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08061f6c
_08077FF2:
	ldr r1, _08078054 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0807804C
	ldr r2, _08078058 @ =0x00000434
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0807804C
	bl FUN_0809c58c
	movs r0, #0xd8
	bl sound_08240740
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r3, [r2]
	cmp r3, #0
	beq _0807804C
	ldr r1, _0807805C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0xc
	add r1, sp, #0x10
	str r0, [r1, #4]
	str r5, [sp, #0xc]
	str r5, [r2]
	adds r0, r3, #0
	bl FUN_082318ac
_0807804C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078054: .4byte 0x0000037D
_08078058: .4byte 0x00000434
_0807805C: .4byte 0xFFFF0000
