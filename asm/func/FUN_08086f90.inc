	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x1a]
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r5, r6, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #0xb0
	ldr r1, _08087004 @ =0x00002499
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r0, #0x84
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldrh r1, [r5]
	ldr r2, _08087008 @ =0x0000032E
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	ldr r0, _0808700C @ =0x00000207
	adds r1, r1, r0
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r0, r6, #0
	adds r0, #0xbc
	subs r4, #0x90
	ldr r2, [r0]
	adds r1, r4, #0
	movs r3, #0xf
_08086FD6:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08086FD6
	adds r0, r6, #0
	adds r0, #0xbc
	str r4, [r0]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08087010
	bl VM_GetValue
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _08087018
	.align 2, 0
_08087004: .4byte 0x00002499
_08087008: .4byte 0x0000032E
_0808700C: .4byte 0x00000207
_08087010:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_08087018:
	ldr r0, _0808704C @ =0x0000922E
	ldr r1, _08087050 @ =0x00003D95
	bl GetFile
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08086024
	ldr r1, _08087054 @ =0x0000031E
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808704C: .4byte 0x0000922E
_08087050: .4byte 0x00003D95
_08087054: .4byte 0x0000031E
