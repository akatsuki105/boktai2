	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r3, r0, #0
	adds r7, r1, #0
	mov sb, r2
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrb r1, [r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r3, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081F5A64
	mov r5, sp
	add r1, sp, #8
	mov r8, r1
	adds r4, r3, #0
	movs r6, #5
_081F59E0:
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, sb
	ble _081F5A4E
	adds r0, r2, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	strh r1, [r4, #0x1c]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1e]
	adds r1, r1, r0
	strh r1, [r4, #0x1e]
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_081F5A4E:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _081F59E0
	b _081F5AFA
_081F5A64:
	ldrb r6, [r2]
	cmp r6, #0
	blt _081F5AFA
	add r5, sp, #0x10
	add r1, sp, #8
	mov r8, r1
	lsls r0, r6, #3
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r4, r0, r3
_081F5A7C:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r1, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, sb
	ble _081F5AE8
	adds r0, r2, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	strh r1, [r4, #0x1c]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x1e]
	adds r1, r1, r0
	strh r1, [r4, #0x1e]
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_081F5AE8:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _081F5B08 @ =0xFFFFFEDC
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _081F5A7C
_081F5AFA:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5B08: .4byte 0xFFFFFEDC
