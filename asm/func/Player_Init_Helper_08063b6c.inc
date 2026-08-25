	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _08063B98 @ =0x00000359
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _08063BA0
	ldr r3, _08063B9C @ =0x000004C4
	adds r0, r5, r3
	movs r4, #0x82
	lsls r4, r4, #1
	adds r1, r5, r4
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
	adds r4, r5, #0
	adds r4, #0xa8
	b _08063BB6
	.align 2, 0
_08063B98: .4byte 0x00000359
_08063B9C: .4byte 0x000004C4
_08063BA0:
	ldr r1, _08063CBC @ =0x000004C4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #1
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
_08063BB6:
	ldr r2, _08063CC0 @ =0x000005FC
	adds r1, r5, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r3, _08063CC4 @ =0x00000604
	adds r0, r5, r3
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08063CC8 @ =0x00000606
	adds r0, r5, r4
	strh r2, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r2, [r0]
	adds r4, #6
	adds r0, r5, r4
	bl FUN_0801385c
	bl FUN_080dc44c
	ldr r1, _08063CCC @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08063BFA
	ldr r2, _08063CD0 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08063BFA
	movs r1, #1
_08063BFA:
	cmp r1, #0
	beq _08063C0E
	ldr r3, _08063CD4 @ =0x0000097A
	adds r1, r5, r3
	movs r0, #0x40
	strh r0, [r1]
	ldr r4, _08063CD8 @ =0x000003F1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_08063C0E:
	adds r0, r5, #0
	bl FUN_08063084
	adds r0, r5, #0
	bl FUN_08061458
	adds r0, r5, #0
	bl FUN_0806161c
	adds r0, r5, #0
	bl FUN_08061dd4
	adds r0, r5, #0
	bl FUN_08062278
	adds r0, r5, #0
	bl Player_Init_Anim_08061bac
	ldr r1, _08063CDC @ =0x0000097C
	adds r0, r5, r1
	movs r2, #0
	movs r1, #4
	strb r1, [r0]
	ldr r3, _08063CE0 @ =0x0000097D
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08063CE4 @ =0x0000097E
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	movs r3, #0
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	ldr r1, _08063CE8 @ =0x00000978
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r2, [r0]
	subs r4, #0x18
	adds r0, r5, r4
	strh r2, [r0]
	subs r1, #4
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _08063CEC @ =0x03002BAC
	strh r2, [r0]
	ldr r0, _08063CF0 @ =0x03002B90
	strh r2, [r0]
	ldr r1, _08063CF4 @ =0x03002B84
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08063CF8 @ =0x03002BF0
	strh r2, [r0]
	ldr r2, _08063CFC @ =0x000003FF
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063CBC: .4byte 0x000004C4
_08063CC0: .4byte 0x000005FC
_08063CC4: .4byte 0x00000604
_08063CC8: .4byte 0x00000606
_08063CCC: .4byte 0x00000446
_08063CD0: .4byte 0x00000442
_08063CD4: .4byte 0x0000097A
_08063CD8: .4byte 0x000003F1
_08063CDC: .4byte 0x0000097C
_08063CE0: .4byte 0x0000097D
_08063CE4: .4byte 0x0000097E
_08063CE8: .4byte 0x00000978
_08063CEC: .4byte 0x03002BAC
_08063CF0: .4byte 0x03002B90
_08063CF4: .4byte 0x03002B84
_08063CF8: .4byte 0x03002BF0
_08063CFC: .4byte 0x000003FF
