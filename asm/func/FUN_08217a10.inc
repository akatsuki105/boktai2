	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	mov r8, r0
	ldr r1, _08217A6C @ =0x082527E0
	add r0, sp, #4
	movs r2, #8
	bl memcpy
	add r6, sp, #0xc
	ldr r1, _08217A70 @ =0x08252804
	adds r0, r6, #0
	movs r2, #8
	bl memcpy
	ldr r4, _08217A74 @ =0x0000166C
	add r4, r8
	movs r0, #1
	mov sb, r0
	ldr r5, _08217A78 @ =0x00001FE6
	add r5, r8
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0x4f
	bgt _08217AA2
	movs r1, #5
	bl Mod
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0x27
	bgt _08217A7C
	movs r1, #5
	bl Div
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	add r1, sp
	adds r1, #4
	ldrb r1, [r1]
	b _08217A94
	.align 2, 0
_08217A6C: .4byte 0x082527E0
_08217A70: .4byte 0x08252804
_08217A74: .4byte 0x0000166C
_08217A78: .4byte 0x00001FE6
_08217A7C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x28
	movs r1, #5
	bl Div
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	add r1, sp
	adds r1, #4
	ldrb r1, [r1]
	adds r1, #0x58
_08217A94:
	strh r1, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r6, r0
	ldrb r0, [r0]
	strh r0, [r4, #0x22]
	b _08217B1E
_08217AA2:
	adds r0, r1, #0
	subs r0, #0x50
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bhi _08217B1E
	lsls r0, r0, #2
	ldr r1, _08217AB8 @ =_08217ABC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08217AB8: .4byte _08217ABC
_08217ABC: @ jump table
	.4byte _08217AD8 @ case 0
	.4byte _08217ADE @ case 1
	.4byte _08217AE8 @ case 2
	.4byte _08217AEC @ case 3
	.4byte _08217AF6 @ case 4
	.4byte _08217B08 @ case 5
	.4byte _08217B14 @ case 6
_08217AD8:
	movs r1, #0
	movs r0, #0xb0
	b _08217AE2
_08217ADE:
	movs r1, #0
	movs r0, #0xc0
_08217AE2:
	strh r0, [r4, #0x20]
	strh r1, [r4, #0x22]
	b _08217B1E
_08217AE8:
	movs r0, #0xb0
	b _08217AEE
_08217AEC:
	movs r0, #0xc0
_08217AEE:
	strh r0, [r4, #0x20]
	movs r0, #0x10
	strh r0, [r4, #0x22]
	b _08217B1E
_08217AF6:
	movs r0, #0
	strh r0, [r4, #0x20]
	ldr r0, _08217B04 @ =0x0000FFF0
	strh r0, [r4, #0x22]
	movs r0, #2
	mov sb, r0
	b _08217B1E
	.align 2, 0
_08217B04: .4byte 0x0000FFF0
_08217B08:
	movs r0, #0
	strh r0, [r4, #0x20]
	strh r0, [r4, #0x22]
	movs r1, #2
	mov sb, r1
	b _08217B1E
_08217B14:
	movs r0, #0
	strh r0, [r4, #0x20]
	strh r0, [r4, #0x22]
	movs r2, #3
	mov sb, r2
_08217B1E:
	mov r1, r8
	adds r1, #0x18
	mov r2, sb
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
