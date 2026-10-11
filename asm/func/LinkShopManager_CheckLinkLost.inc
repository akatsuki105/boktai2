	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1BA8
	movs r0, #1
	b _081E1BAA
_081E1BA8:
	movs r0, #0
_081E1BAA:
	adds r7, r0, #0
	cmp r7, #0
	bne _081E1C80
	movs r0, #0
	mov r8, r0
	bl Sio_GetMultiId
	adds r5, r0, #0
	cmp r5, #0
	beq _081E1BC8
	cmp r5, #1
	beq _081E1BE4
	adds r1, r6, #0
	adds r1, #0x6b
	b _081E1C0E
_081E1BC8:
	bl Sio_HasChildData
	mov r8, r0
	bl Sio_GetTimerIntrCount
	ldr r1, [r6, #0x70]
	cmp r1, r0
	beq _081E1BF4
	adds r4, r6, #0
	adds r4, #0x6b
	strb r5, [r4]
	bl Sio_GetTimerIntrCount
	b _081E1C0A
_081E1BE4:
	bl Sio_HasParentData
	mov r8, r0
	bl Sio_GetSerialIntrCount
	ldr r1, [r6, #0x70]
	cmp r1, r0
	bne _081E1C00
_081E1BF4:
	adds r1, r6, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081E1C0E
_081E1C00:
	adds r4, r6, #0
	adds r4, #0x6b
	strb r7, [r4]
	bl Sio_GetSerialIntrCount
_081E1C0A:
	str r0, [r6, #0x70]
	adds r1, r4, #0
_081E1C0E:
	ldrb r0, [r1]
	cmp r0, #0xa
	bhi _081E1C2C
	mov r0, r8
	cmp r0, #0
	bne _081E1C30
	adds r1, r6, #0
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _081E1C38
_081E1C2C:
	movs r0, #1
	b _081E1C82
_081E1C30:
	adds r1, r6, #0
	adds r1, #0x6c
	movs r0, #0
	strb r0, [r1]
_081E1C38:
	bl Sio_GetError
	cmp r0, #0
	blt _081E1C2C
	bl Sio_GetMultiId
	cmp r0, #0
	blt _081E1C80
	bl Sio_GetMultiId
	adds r1, r6, #0
	adds r1, #0x6d
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r4, r1, #0
	cmp r0, r2
	beq _081E1C80
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1C6A
	movs r0, #1
	b _081E1C6C
_081E1C6A:
	movs r0, #0
_081E1C6C:
	cmp r0, #0
	bne _081E1C2C
	bl Sio_GetMultiId
	strb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_081E1C80:
	movs r0, #0
_081E1C82:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
