	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081DC5A2
	bl VM_GetPC_Proxy
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DC5A2
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC622
_081DC5A2:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	ldr r2, _081DC62C @ =0x000003DA
	adds r1, r5, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db9f4
	adds r0, r5, #0
	bl FUN_081dbc14
	adds r0, r5, #0
	bl FUN_081dbc60
	adds r0, r5, #0
	bl FUN_081dbd74
	adds r0, r5, #0
	bl FUN_081dbce4
	adds r0, r5, #0
	bl FUN_081dba54
	ldr r1, _081DC630 @ =FUN_081dc38c
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _081DC61C
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DC634 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl StartBgObjPlttFade
_081DC61C:
	ldr r0, _081DC638 @ =0x030001A8
	str r5, [r0]
	movs r0, #1
_081DC622:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DC62C: .4byte 0x000003DA
_081DC630: .4byte FUN_081dc38c
_081DC634: .4byte 0x0000FFFF
_081DC638: .4byte 0x030001A8
