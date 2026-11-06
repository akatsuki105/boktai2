	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xba
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F8ECA
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F8ECA:
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081F8EFC
	adds r1, r5, #0
	adds r1, #0x9c
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r2, [r1]
	ldr r0, [r0]
	adds r2, r2, r0
	str r2, [r1]
	movs r0, #0xff
	lsls r0, r0, #0xc
	cmp r2, r0
	bls _081F8F0E
	ldr r3, _081F8EF8 @ =0xFFF01000
	adds r0, r2, r3
	str r0, [r1]
	b _081F8F0E
	.align 2, 0
_081F8EF8: .4byte 0xFFF01000
_081F8EFC:
	adds r2, r5, #0
	adds r2, #0x9c
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	adds r1, r2, #0
_081F8F0E:
	ldr r1, [r1]
	adds r0, r5, #0
	adds r0, #0xa8
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r6, r5, #0
	adds r6, #0x94
	lsrs r4, r1, #0xc
	lsls r0, r0, #7
	mov ip, r0
	ldr r2, _081F8F44 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r7, r6, #0
	cmp r0, #0
	blt _081F8F48
	asrs r3, r0, #0xc
	b _081F8F4E
	.align 2, 0
_081F8F44: .4byte gSineTable
_081F8F48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081F8F4E:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081F8F6E
	asrs r1, r0, #0xc
	b _081F8F74
_081F8F6E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F8F74:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x96
	strh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x1c
	subs r1, #0xa
	ldrh r0, [r1]
	ldrh r2, [r7]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r0, [r4]
	movs r1, #0x1e
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081F8FCC
	ldr r2, _081F9004 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F9008 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F900C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081F8FCC
	adds r0, r6, #0
	bl Entity081f959c_SpawnTrail
_081F8FCC:
	adds r0, r5, #0
	bl Entity081f959c_UpdateHitbox
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F9010
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F9018
	.align 2, 0
_081F9004: .4byte 0x030046B8
_081F9008: .4byte 0x000003FF
_081F900C: .4byte 0x0203B400
_081F9010:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F9018:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F903C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F9044
_081F903C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F9044:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081F907C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F90B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F9080
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F9074
	ldrb r0, [r4, #5]
_081F9074:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F9090
	.align 2, 0
_081F907C: .4byte 0x0000FFFF
_081F9080:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F9090
	strh r1, [r4, #8]
_081F9090:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F90B4
	movs r0, #1
	strb r0, [r4, #7]
_081F90B4:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	adds r1, r5, #0
	adds r1, #0xb0
	ldr r0, [r1]
	cmp r0, #0
	ble _081F90CA
	subs r0, #1
	str r0, [r1]
	b _081F90D8
_081F90CA:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #3
	strb r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
_081F90D8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
