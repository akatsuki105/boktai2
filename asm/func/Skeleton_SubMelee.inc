	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0810FF78 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810FF7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810FF7E
	.align 2, 0
_0810FF78: .4byte 0x0000046C
_0810FF7C:
	movs r0, #0
_0810FF7E:
	cmp r0, #0
	beq _0810FFE8
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r5, #0
	movs r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0810FFA4 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0810FFAC
	ldr r3, _0810FFA8 @ =Skeleton_StateArcherMelee
	b _0810FFAE
	.align 2, 0
_0810FFA4: .4byte 0x000001DF
_0810FFA8: .4byte Skeleton_StateArcherMelee
_0810FFAC:
	ldr r3, _08110008 @ =Skeleton_StateMelee
_0810FFAE:
	movs r2, #3
	ldr r0, _0811000C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110010 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Skeleton_SetAtkHitbox2Attack
	ldr r2, _08110014 @ =0x0000074C
	adds r0, r6, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r6, r2
	strh r1, [r0]
_0810FFE8:
	ldr r1, _08110010 @ =0x0000046B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811001C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, _08110018 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl Skeleton_RetreatOrChase
	b _08110026
	.align 2, 0
_08110008: .4byte Skeleton_StateMelee
_0811000C: .4byte 0x0000046D
_08110010: .4byte 0x0000046B
_08110014: .4byte 0x0000074C
_08110018: .4byte 0xFFFFFEFF
_0811001C:
	ldr r0, _0811002C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110026:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811002C: .4byte 0x00000484
