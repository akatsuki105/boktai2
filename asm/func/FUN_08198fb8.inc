	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	mov sb, r0
	movs r2, #0
	ldr r7, _08199018 @ =0x00000183
	adds r3, r1, r7
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	bge _0819902A
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r0, r0, r1
	mov ip, r0
	subs r7, #3
	adds r6, r1, r7
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r5, r1, r0
	subs r7, #0x10
	adds r4, r1, r7
	movs r0, #0x1e
	mov sl, r0
	ldr r7, _0819901C @ =FUN_08199064
	mov r8, r7
_08198FFA:
	mov r7, ip
	ldrb r0, [r7]
	ldrb r7, [r1, #6]
	adds r0, r0, r7
	strb r0, [r1, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r7, [r6]
	cmp r0, r7
	bne _08199020
	mov r0, sl
	str r0, [r5]
	mov r2, r8
	str r2, [r4]
	b _0819904C
	.align 2, 0
_08199018: .4byte 0x00000183
_0819901C: .4byte FUN_08199064
_08199020:
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _08198FFA
_0819902A:
	ldr r0, _0819905C @ =0x00000CEC
	add r0, sb
	ldr r0, [r0]
	movs r2, #7
	ands r0, r2
	cmp r0, #0
	bne _0819904C
	ldr r7, _08199060 @ =0x00000183
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _0819904C
	strb r2, [r1]
_0819904C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819905C: .4byte 0x00000CEC
_08199060: .4byte 0x00000183
