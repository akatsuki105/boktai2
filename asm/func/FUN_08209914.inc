	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08209938 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08209AB6
	.align 2, 0
_08209938: .4byte 0x03002B4C
_0820993C:
	ldr r0, _08209970 @ =0x03002B4C
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
	ldr r6, [r0]
	mov r0, sb
	adds r1, r6, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r6, #6]
	cmp r0, #0x14
	bls _08209964
	b _08209AA8
_08209964:
	lsls r0, r0, #2
	ldr r1, _08209974 @ =_08209978
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08209970: .4byte 0x03002B4C
_08209974: .4byte _08209978
_08209978: @ jump table
	.4byte _082099CC @ case 0
	.4byte _082099D8 @ case 1
	.4byte _08209A7C @ case 2
	.4byte _082099F0 @ case 3
	.4byte _08209AA8 @ case 4
	.4byte _08209AA8 @ case 5
	.4byte _08209AA8 @ case 6
	.4byte _08209AA8 @ case 7
	.4byte _08209AA8 @ case 8
	.4byte _08209AA8 @ case 9
	.4byte _08209A96 @ case 10
	.4byte _08209AA8 @ case 11
	.4byte _08209AA8 @ case 12
	.4byte _08209AA8 @ case 13
	.4byte _08209AA8 @ case 14
	.4byte _08209AA8 @ case 15
	.4byte _08209AA8 @ case 16
	.4byte _08209AA8 @ case 17
	.4byte _08209AA8 @ case 18
	.4byte _08209AA8 @ case 19
	.4byte _08209A36 @ case 20
_082099CC:
	movs r0, #0
	strb r0, [r7, #2]
	strb r0, [r7, #3]
	strb r0, [r7, #4]
	str r0, [r7, #0x14]
	b _08209A90
_082099D8:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #1
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	strb r0, [r7, #8]
	b _08209AA8
_082099F0:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #0x1b]
	movs r0, #0x10
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _08209A90
_08209A36:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #0x1b]
	movs r0, #2
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _08209A90
_08209A7C:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #3
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
_08209A90:
	movs r0, #1
	strb r0, [r7, #8]
	b _08209AA8
_08209A96:
	movs r0, #8
	ldrsh r1, [r6, r0]
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	movs r0, #0xc
	ldrsh r3, [r6, r0]
	adds r0, r7, #0
	bl FUN_080415cc
_08209AA8:
	movs r1, #1
	add r8, r1
	ldr r0, _08209AD0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08209AB6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08209AC2
	b _0820993C
_08209AC2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209AD0: .4byte 0x03002B4C
