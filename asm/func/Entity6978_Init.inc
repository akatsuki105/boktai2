	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08002930 @ =0x03002B30
	str r4, [r0]
	movs r5, #0
	strh r1, [r4, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r4, #0x1a]
	strh r5, [r4, #0x1c]
	strh r5, [r4, #0x1e]
	strh r5, [r4, #0x20]
	strh r5, [r4, #0x22]
	strh r5, [r4, #0x24]
	movs r1, #0
	movs r0, #6
	adds r4, #0x32
_08002906:
	strh r1, [r4]
	subs r4, #2
	subs r0, #1
	cmp r0, #0
	bge _08002906
	movs r2, #0
	ldr r0, _08002934 @ =0x0300445C
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _08002938 @ =0x0300404C
	str r1, [r0]
	ldr r1, _0800293C @ =0x03004464
	ldr r3, _08002940 @ =0x00001084
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _08002944 @ =0x03004490
	strh r2, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08002930: .4byte 0x03002B30
_08002934: .4byte 0x0300445C
_08002938: .4byte 0x0300404C
_0800293C: .4byte 0x03004464
_08002940: .4byte 0x00001084
_08002944: .4byte 0x03004490
