	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _0818FA0C @ =0x00000ECC
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0818FA5C
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _0818FA10 @ =0x00000F36
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _0818FA5C
	movs r0, #2
	mov sl, r0
	movs r2, #1
	mov sb, r2
	mov r8, r1
	adds r3, r7, #0
	ldr r7, _0818FA14 @ =0x0000077A
	adds r4, r3, r7
_0818F9FC:
	ldrh r0, [r4]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _0818FA18
	movs r0, #1
	b _0818FA1A
	.align 2, 0
_0818FA0C: .4byte 0x00000ECC
_0818FA10: .4byte 0x00000F36
_0818FA14: .4byte 0x0000077A
_0818FA18:
	movs r0, #0
_0818FA1A:
	cmp r0, #0
	beq _0818FA46
	ldrh r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0818FA2C
	movs r0, #1
	b _0818FA2E
_0818FA2C:
	movs r0, #0
_0818FA2E:
	cmp r0, #0
	bne _0818FA46
	ldr r7, _0818FA6C @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xf0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_0818FA46:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r4, r4, r0
	movs r1, #1
	add ip, r1
	mov r2, r8
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp ip, r0
	blt _0818F9FC
_0818FA5C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818FA6C: .4byte 0x00000674
