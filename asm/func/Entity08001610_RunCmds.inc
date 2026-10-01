	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0
	mov sl, r0
	b _080011C0
_08001082:
	mov r1, sl
	lsls r0, r1, #1
	adds r1, r7, #0
	adds r1, #0x68
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r2, sl
	lsls r0, r2, #4
	adds r0, #0x78
	adds r3, r7, r0
	cmp r1, #5
	bls _0800109C
	b _080011BC
_0800109C:
	lsls r0, r1, #2
	ldr r1, _080010A8 @ =_080010AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080010A8: .4byte _080010AC
_080010AC: @ jump table
	.4byte _080010C4 @ case 0
	.4byte _080010D6 @ case 1
	.4byte _08001124 @ case 2
	.4byte _08001134 @ case 3
	.4byte _080011AC @ case 4
	.4byte _080011B4 @ case 5
_080010C4:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	strh r0, [r7, #0x26]
	strh r0, [r7, #0x28]
	b _080011BC
_080010D6:
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldrh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x48
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x46
	strh r2, [r0]
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #4
	strh r0, [r7, #0x38]
	movs r2, #4
	ldrsh r0, [r3, r2]
	lsls r0, r0, #4
	strh r0, [r7, #0x3a]
	movs r3, #0x38
	ldrsh r0, [r7, r3]
	movs r2, #0x1e
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	strh r0, [r7, #0x26]
	movs r3, #0x3a
	ldrsh r0, [r7, r3]
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	strh r0, [r7, #0x28]
	b _080011BC
_08001124:
	ldrb r0, [r7, #0x1b]
	movs r4, #0
	ldrsh r1, [r3, r4]
	movs r4, #2
	ldrsh r2, [r3, r4]
	bl FUN_0822f178
	b _080011BC
_08001134:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x52
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0x56
	strh r0, [r2]
	movs r1, #0x54
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	adds r6, r7, #0
	adds r6, #0x58
	strh r0, [r6]
	ldrh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x50
	strh r0, [r4]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r3, #4]
	lsls r0, r0, #8
	adds r5, r7, #0
	adds r5, #0x5c
	strh r0, [r5]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	adds r1, r7, #0
	adds r1, #0x5e
	strh r0, [r1]
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	adds r1, r7, #0
	adds r1, #0x60
	strh r0, [r1]
	ldrb r0, [r7, #0x1b]
	mov r2, sb
	ldrh r1, [r2]
	lsrs r1, r1, #8
	mov r3, r8
	ldrh r2, [r3]
	lsrs r2, r2, #8
	bl FUN_0822f178
	b _080011BC
_080011AC:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	b _080011BA
_080011B4:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #1
_080011BA:
	strb r0, [r1]
_080011BC:
	movs r4, #1
	add sl, r4
_080011C0:
	ldr r0, [r7, #0x64]
	cmp sl, r0
	bhs _080011C8
	b _08001082
_080011C8:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
