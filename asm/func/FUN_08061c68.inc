	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _08061CC0 @ =0x0000071C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061D10
	movs r2, #0
	mov r8, r2
	movs r7, #0
_08061C80:
	movs r0, #0x34
	adds r1, r7, #0
	muls r1, r0, r1
	adds r0, r5, r1
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061CFE
	subs r2, #0x30
	adds r0, r1, r2
	adds r3, r5, r0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strb r2, [r1]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _08061CC4
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x30
	strb r6, [r0]
	b _08061CFE
	.align 2, 0
_08061CC0: .4byte 0x0000071C
_08061CC4:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08061CE2
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_08061CE2:
	ldrh r0, [r4, #0x28]
	ldrh r2, [r4, #0x18]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r0, #1
	add r8, r0
_08061CFE:
	adds r7, #1
	cmp r7, #5
	ble _08061C80
	mov r1, r8
	cmp r1, #0
	bne _08061D10
	ldr r2, _08061D1C @ =0x0000071C
	adds r0, r5, r2
	strb r1, [r0]
_08061D10:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061D1C: .4byte 0x0000071C
