	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r4, _0807ED98 @ =0x030046A0
	ldr r1, [r4]
	ldrh r0, [r0, #0x2c]
	strh r0, [r1, #0x30]
	ldr r1, [r4]
	mov r2, ip
	ldrh r0, [r2, #0x2e]
	strh r0, [r1, #0x32]
	ldr r1, [r4]
	ldrh r0, [r2, #0x30]
	strh r0, [r1, #0x34]
	ldr r1, [r4]
	movs r5, #0xba
	lsls r5, r5, #2
	add r5, ip
	ldrb r0, [r5]
	strh r0, [r1, #0x36]
	ldr r2, [r4]
	ldr r3, _0807ED9C @ =0x00000932
	adds r2, r2, r3
	ldrb r0, [r5]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
	ldr r1, [r4]
	adds r3, r1, r3
	ldrh r0, [r3]
	mov r2, ip
	adds r2, #0x29
	strb r0, [r2]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r2, #0xd7
	lsls r2, r2, #1
	add r2, ip
	strb r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0xd6
	lsls r2, r2, #2
	add r2, ip
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x93
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0xdf
	lsls r1, r1, #2
	add r1, ip
	ldrb r1, [r1]
	strh r1, [r0]
	ldrb r0, [r2]
	cmp r0, #5
	bne _0807EDA0
	ldr r1, [r4]
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x38]
	ldr r1, [r4]
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x3a]
	b _0807EDB8
	.align 2, 0
_0807ED98: .4byte 0x030046A0
_0807ED9C: .4byte 0x00000932
_0807EDA0:
	ldr r1, [r4]
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r0, #0xda
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2c]
_0807EDB8:
	ldr r1, [r4]
	ldr r0, _0807EE24 @ =0x00000366
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2a]
	ldr r1, [r4]
	ldr r0, _0807EE28 @ =0x0000036A
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #0x2e]
	ldr r1, _0807EE2C @ =0x03002B60
	ldr r0, _0807EE30 @ =0x00000442
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807EE34 @ =0x03002B7C
	ldr r0, _0807EE38 @ =0x00000444
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807EE3C @ =0x03002B8C
	ldr r0, _0807EE40 @ =0x00000446
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r5, _0807EE44 @ =0x03002BC0
	mov r4, ip
	adds r4, #0x28
	ldr r6, _0807EE48 @ =0x03002BB0
	ldr r1, _0807EE4C @ =0x0000043C
	add r1, ip
	ldr r3, _0807EE50 @ =0x03002BA0
	movs r2, #2
_0807EDFA:
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0807EDFA
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r2, ip
	ldr r1, [r2, #0x1c]
	str r1, [r0]
	ldr r0, _0807EE54 @ =0x00000283
	add r0, ip
	ldrb r0, [r0]
	strh r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EE24: .4byte 0x00000366
_0807EE28: .4byte 0x0000036A
_0807EE2C: .4byte 0x03002B60
_0807EE30: .4byte 0x00000442
_0807EE34: .4byte 0x03002B7C
_0807EE38: .4byte 0x00000444
_0807EE3C: .4byte 0x03002B8C
_0807EE40: .4byte 0x00000446
_0807EE44: .4byte 0x03002BC0
_0807EE48: .4byte 0x03002BB0
_0807EE4C: .4byte 0x0000043C
_0807EE50: .4byte 0x03002BA0
_0807EE54: .4byte 0x00000283
