	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r5, r0, #0
	adds r1, r5, #0
	movs r2, #0
	bl Enemy_SetOwnerAndSpriteKind
	strh r4, [r5]
	ldr r0, _08188900 @ =0x000001DF
	adds r1, r5, r0
	movs r0, #0xf
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0818890E
	movs r0, #0xce
	lsls r0, r0, #1
	adds r6, r5, r0
	movs r4, #4
_081888F2:
	bl VM_GetPC
	cmp r0, #0
	beq _08188904
	bl VM_GetValue
	b _08188906
	.align 2, 0
_08188900: .4byte 0x000001DF
_08188904:
	movs r0, #0
_08188906:
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081888F2
_0818890E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _08188950 @ =0x0000060C
	adds r1, r5, r0
	ldr r0, _08188954 @ =0x085ADCD0
	str r0, [r1]
	ldr r2, _08188958 @ =0x0000057C
	adds r1, r5, r2
	ldr r0, _0818895C @ =Enemy_DispatchMsg
	str r0, [r1]
	ldr r0, _08188960 @ =0x0000061C
	adds r1, r5, r0
	ldr r0, _08188964 @ =OctopusGroup_Update
	str r0, [r1]
	adds r2, #0xa4
	adds r1, r5, r2
	ldr r0, _08188968 @ =OctopusGroup_Destroy
	str r0, [r1]
	adds r0, r5, #0
	bl Enemy_Register
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0818896C
	movs r0, #0
	b _08188970
	.align 2, 0
_08188950: .4byte 0x0000060C
_08188954: .4byte 0x085ADCD0
_08188958: .4byte 0x0000057C
_0818895C: .4byte Enemy_DispatchMsg
_08188960: .4byte 0x0000061C
_08188964: .4byte OctopusGroup_Update
_08188968: .4byte OctopusGroup_Destroy
_0818896C:
	movs r0, #1
	rsbs r0, r0, #0
_08188970:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
