	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08044F74 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0804506A
	.align 2, 0
_08044F74: .4byte 0x03002B4C
_08044F78:
	ldr r0, _08044FAC @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl EntityMsgBox_BeginWait
	ldrb r0, [r7, #6]
	subs r0, #1
	cmp r0, #8
	bhi _0804505C
	lsls r0, r0, #2
	ldr r1, _08044FB0 @ =_08044FB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044FAC: .4byte 0x03002B4C
_08044FB0: .4byte _08044FB4
_08044FB4: @ jump table
	.4byte _0804501E @ case 0
	.4byte _08044FD8 @ case 1
	.4byte _08045034 @ case 2
	.4byte _08045038 @ case 3
	.4byte _0804503C @ case 4
	.4byte _08045040 @ case 5
	.4byte _08045044 @ case 6
	.4byte _08045048 @ case 7
	.4byte _0804504C @ case 8
_08044FD8:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0804505A
_0804501E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08045058
_08045034:
	movs r1, #3
	b _0804504E
_08045038:
	movs r1, #4
	b _0804504E
_0804503C:
	movs r1, #5
	b _0804504E
_08045040:
	movs r1, #6
	b _0804504E
_08045044:
	movs r1, #7
	b _0804504E
_08045048:
	movs r1, #8
	b _0804504E
_0804504C:
	movs r1, #9
_0804504E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
	str r0, [r6, #0x14]
_08045058:
	movs r0, #1
_0804505A:
	strb r0, [r6, #8]
_0804505C:
	movs r7, #1
	add r8, r7
	ldr r0, _08045084 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0804506A:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08045076
	b _08044F78
_08045076:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045084: .4byte 0x03002B4C
