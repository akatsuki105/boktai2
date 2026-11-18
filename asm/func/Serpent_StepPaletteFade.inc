	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819311A
	b _0819326C
_0819311A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r3, _08193138 @ =0x00000F2C
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819313C
	movs r0, #1
	b _0819313E
	.align 2, 0
_08193138: .4byte 0x00000F2C
_0819313C:
	movs r0, #0
_0819313E:
	cmp r0, #0
	bne _08193144
	b _0819326C
_08193144:
	ldr r0, _08193174 @ =0x00000D58
	adds r0, r0, r2
	mov ip, r0
	ldrh r0, [r0, #0x20]
	cmp r0, #0
	bne _08193180
	ldr r1, _08193178 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08193162
	b _08193278
_08193162:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, _0819317C @ =0x000001A9
	strh r1, [r0, #0x32]
	mov r2, r8
	ldr r0, [r2, #0x44]
	mov r3, ip
	str r3, [r0, #0x38]
	b _08193278
	.align 2, 0
_08193174: .4byte 0x00000D58
_08193178: .4byte 0x02008000
_0819317C: .4byte 0x000001A9
_08193180:
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	str r0, [sp]
	ldr r1, _081931E0 @ =0x00000D7C
	adds r1, r2, r1
	str r1, [sp, #4]
	ldr r3, _081931E4 @ =0x00000DDC
	adds r3, r2, r3
	str r3, [sp, #8]
	ldr r0, _081931E8 @ =0x00000DFC
	adds r0, r0, r2
	mov sl, r0
	ldr r1, _081931EC @ =0x00000E1C
	adds r1, r1, r2
	mov sb, r1
	mov r5, ip
	ldr r3, _081931F0 @ =0x00000DBC
	adds r4, r2, r3
	movs r7, #0
	ldr r0, _081931F4 @ =0x00000D9C
	adds r3, r2, r0
_081931AC:
	ldr r2, [sp, #4]
	adds r1, r2, r7
	ldr r2, [sp, #8]
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r2, sl
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	mov r2, sb
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _081931F8
	asrs r0, r0, #5
	b _081931FE
	.align 2, 0
_081931E0: .4byte 0x00000D7C
_081931E4: .4byte 0x00000DDC
_081931E8: .4byte 0x00000DFC
_081931EC: .4byte 0x00000E1C
_081931F0: .4byte 0x00000DBC
_081931F4: .4byte 0x00000D9C
_081931F8:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081931FE:
	adds r6, r0, #0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0819320C
	asrs r0, r0, #5
	b _08193212
_0819320C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_08193212:
	adds r2, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08193220
	asrs r1, r0, #5
	b _08193226
_08193220:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08193226:
	lsls r0, r2, #5
	orrs r0, r6
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r5]
	adds r5, #2
	adds r4, #2
	adds r7, #2
	adds r3, #2
	mov r0, ip
	adds r0, #0x1e
	cmp r5, r0
	ble _081931AC
	mov r2, ip
	ldrh r0, [r2, #0x20]
	subs r0, #1
	strh r0, [r2, #0x20]
	ldr r1, _08193270 @ =0x02008000
	ldr r3, [sp]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08193264
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, _08193274 @ =0x000001A9
	strh r1, [r0, #0x32]
	mov r2, r8
	ldr r0, [r2, #0x44]
	mov r3, ip
	str r3, [r0, #0x38]
_08193264:
	mov r1, ip
	ldrh r0, [r1, #0x20]
	cmp r0, #0
	beq _08193278
_0819326C:
	movs r0, #0
	b _0819327A
	.align 2, 0
_08193270: .4byte 0x02008000
_08193274: .4byte 0x000001A9
_08193278:
	movs r0, #1
_0819327A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
